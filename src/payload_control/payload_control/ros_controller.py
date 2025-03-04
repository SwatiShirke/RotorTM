import rclpy
from rclpy.node import Node
from geometry_msgs.msg import PointStamped, PoseStamped
from nav_msgs.msg import Odometry, Path
from sensor_msgs.msg import Imu
from std_msgs.msg import Bool, Empty
from rotor_tm_msgs.msg import FMNCommand, PositionCommand, TrajCommand
import numpy as np
import math
from payload_control.payload_controller import *
from rotor_tm_utils import read_params


class NMPCControlNode(Node):
    def __init__(self, model, acados_solver, acados_integrator):
        super().__init__('nmpc_control_node')
        
        # Store the control model and solvers
        self.model = model
        self.acados_solver = acados_solver
        self.acados_integrator = acados_integrator
        # Initialize parameters and state variables
        self.frame_id = 'simulator'
        self.pre_odom_quat = np.array([1.0, 0.0, 0.0, 0.0])
        self.set_pre_odom_quat = False
        
        self.mass = 0.278
        self.gravity = 9.81
        self.hover_thrust = self.mass * self.gravity
        self.mass_matrix = self.mass * np.eye(3)
        
        # Publishers
        self.pub_FMN_cmd = self.create_publisher(FMNCommand, '/payload/pl_nmpc_FMN_cmd', 10)
        self.pub_ref_traj = self.create_publisher(Path, '/payload/reference_path', 1)
        self.pub_pred_traj = self.create_publisher(Path, '/payload/predicted_path', 1)
        self.current_state = np.zeros((13,1))
        # Subscribers
        self.sub_traj_cmd = self.create_subscription(
            TrajCommand, '/payload/des_traj_n', self.reference_callback, 10)
        self.sub_odometry = self.create_subscription(
            Odometry, '/payload/odom', self.odom_callback, 10)
        
        self.get_logger().info("NMPC Control Node Initialized.")

    def reference_callback(self, reference_msg):
        """ Handle incoming reference trajectory message. """
        self.get_logger().info(f"Received reference trajectory with {len(reference_msg.points)} points.")
        
        # Adjust quaternion signs based on the previous quaternion
        pre_quat = self.pre_odom_quat
        for point in reference_msg.points:
            current_quat = np.array([point.quaternion.w, point.quaternion.x, point.quaternion.y, point.quaternion.z])
            if np.dot(current_quat, pre_quat) < 0:
                point.quaternion.w = -point.quaternion.w
                point.quaternion.x = -point.quaternion.x
                point.quaternion.y = -point.quaternion.y
                point.quaternion.z = -point.quaternion.z
            pre_quat = current_quat

        # Process the reference states and inputs (like the C++ version)
        reference_states = np.zeros((len(reference_msg.points), 13))  # Placeholder for state matrix
        reference_inputs = np.zeros((len(reference_msg.points), 9))  # Placeholder for input matrix

        for i, point in enumerate(reference_msg.points):
            reference_states[i] = np.array([
                point.position.x, point.position.y, point.position.z,
                point.velocity.x, point.velocity.y, point.velocity.z,
                point.quaternion.w, point.quaternion.x, point.quaternion.y, point.quaternion.z,
                point.angular_velocity.x, point.angular_velocity.y, point.angular_velocity.z
            ])

            lin_acc = np.array([point.acceleration.x, point.acceleration.y, point.acceleration.z])
            force = self.mass_matrix @ lin_acc + self.hover_thrust * np.array([0, 0, 1])
            reference_inputs[i] = np.concatenate([force, np.zeros(6)])
            concatenated = np.concatenate((reference_states[i], reference_inputs[ i]))
            acados_solver.set(i, "p", concatenated)
        
        acados_solver.set(9, "p", concatenated) 
        acados_solver.set(0, "lbx",self.current_state )
        acados_solver.set(0, "ubx", self.current_state)
        self.control_input = acados_solver.get(0, "u") 
        # Publish reference and inputs (you can expand on this)
        self.publish_control(self.control_input)
        self.publish_reference(reference_states)
        #self.publish_prediction()

    def odom_callback(self, odom_msg):
        """ Handle incoming odometry message. """
        self.get_logger().info(f"Received odometry: {odom_msg.pose.pose.position.x}, {odom_msg.pose.pose.position.y}")
        
        # Extract position and orientation from the odometry message
        position = odom_msg.pose.pose.position
        orientation = odom_msg.pose.pose.orientation
        self.current_state = [position.x, position.y, position.z, orientation.w, orientation.x, orientation.y, orientation.z, 0,0,0, 0,0,0]
        # You can process this data to update your control or state estimation
        # Example: Calculate velocity, acceleration, or other state-related variables

    def publish_control(self):
        """ Publish the control command (FMNCommand). """
        # Calculate control forces and moments
        # Example: Assuming we're using the reference trajectory for control calculation
        fmn_cmd_msg = FMNCommand()

        # Here you would calculate the desired forces, moments, and control based on your NMPC strategy.
        # For example:
        
        # Example force calculation (simplified)
        desired_force = self.control_input[0:3]  # Simplified, adjust with your model
        
        # Example moment calculation (simplified)
        desired_moment = self.control_input[3:6]  # Simplified, adjust with your model
        
        fmn_cmd_msg.header.stamp = ""
        fmn_cmd_msg.header.frame_id = self.frame_id_
        fmn_cmd_msg.thrust = desired_force
        fmn_cmd_msg.moment = desired_moment

        ## Publish the FMNCommand message
        self.pub_FMN_cmd.publish(fmn_cmd_msg)
        #self.get_logger().info(f"Published FMN Command: Thrust: {desired_force[2]}, Moments: {desired_moment}")

    def publish_reference(self, reference_states):
        """ Publish the reference trajectory (Path message). """
        path_msg = Path()
        # Populate the path message based on reference_states (e.g., using PoseStamped)
        for state in reference_states:  # Transpose to iterate over samples
            pose_stamped = PoseStamped()
            pose_stamped.header.frame_id = self.frame_id
            pose_stamped.pose.position.x = state[0]
            pose_stamped.pose.position.y = state[1]
            pose_stamped.pose.position.z = state[2]
            # Set orientation if needed (e.g., quaternion)
            #Set quaternion (orientation)
            pose_stamped.pose.orientation.w = state[6]  # Quaternion w
            pose_stamped.pose.orientation.x = state[7]  # Quaternion x
            pose_stamped.pose.orientation.y = state[8]  # Quaternion y
            pose_stamped.pose.orientation.z = state[9]  # Quaternion z

            path_msg.poses.append(pose_stamped)
        self.pub_ref_traj.publish(path_msg)

    def publish_prediction(self, reference_inputs):
        """ Publish the predicted trajectory (Path message). """
        path_msg = Path()
        # Populate the path message based on reference_inputs (e.g., using PoseStamped)
        for input_vec in reference_inputs.T:  # Transpose to iterate over samples
            pose_stamped = PoseStamped()
            pose_stamped.header.frame_id = self.frame_id
            pose_stamped.pose.position.x = input_vec[0]
            pose_stamped.pose.position.y = input_vec[1]
            pose_stamped.pose.position.z = input_vec[2]
            # Set velocity, acceleration, or other data as needed
            path_msg.poses.append(pose_stamped)
        self.pub_pred_traj.publish(path_msg)


    
if __name__ == '__main__':
    # Define the paths to your configuration files
    nmpc_filename = "/home/dhruv/RotorTM/src/rotor_tm_config/config/control_params/payload_nmpc_params.yaml"
    payload_params_path = "/home/dhruv/RotorTM/src/rotor_tm_config/config/load_params/triangular_payload.yaml"
    uav_params_path = "/home/dhruv/RotorTM/src/rotor_tm_config/config/uav_params/"
    mechanism_params_path = "/home/dhruv/RotorTM/src/rotor_tm_config/config/attach_mechanism/cable/3_robots_triangular_payload_0-5m.yaml"
    payload_control_gain_path = "/home/dhruv/RotorTM/src/rotor_tm_config/config/control_params/triangular_payload_cooperative_cable_gains.yaml"
    uav_control_gain_path = "/home/dhruv/RotorTM/src/rotor_tm_config/config/control_params/"

    # Read the parameters using your read_params module
    read_params_funcs = read_params.read_params()
    payload_params, quad_params = read_params_funcs.system_setup(payload_params_path, uav_params_path, mechanism_params_path, payload_control_gain_path, uav_control_gain_path)
    control_params = read_params_funcs.read_pl_nmpc_params(nmpc_filename)
    
    # Set up the controller (model, solver, integrator)
    model, acados_solver, acados_integrator = controller_setup(control_params, payload_params)
    
    # Initialize ROS 2 and the NMPCControlNode, passing the model and solvers
    rclpy.init()
    node = NMPCControlNode(model, acados_solver, acados_integrator)
    rclpy.spin(node)
    rclpy.shutdown()