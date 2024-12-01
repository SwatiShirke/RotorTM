#!/usr/bin/env python3
from rotor_tm_traj import traj
import rclpy
from rclpy.node import Node
from rclpy.clock import Clock
from rclpy.qos import QoSProfile, QoSReliabilityPolicy, QoSHistoryPolicy
import numpy as np
from rotor_tm_traj import map
from rotor_tm_traj import create_options
from matplotlib import pyplot as plt

# ROS 2 message and service imports
from rotor_tm_msgs.msg import PositionCommand
from nav_msgs.msg import Odometry
from std_msgs.msg import Header
from rotor_tm_msgs.srv import Circle, Line, CircleWithRotation, StepPose
from scipy.spatial.transform import Rotation as rot


class TrajNode(Node):
    def __init__(self):
        super().__init__('traj_node')
        
        # Initialize attributes
        self.timer_period = 0.1
        self.radius = None
        self.period = None
        self.duration = None
        self.payload_start = None
        self.time_reference = None
        self.map = map.map()
        self.map.load_map()
        self.path = None
        self.curr_pose = np.append(np.zeros(3), np.array([1, 0, 0, 0]))
        self.traj_start = False
        self.is_finished = True
        
        #QoS profile 
        qos_profile = QoSProfile(
            reliability=QoSReliabilityPolicy.BEST_EFFORT,  # Best effort, similar to TCP no delay
            history=QoSHistoryPolicy.KEEP_LAST,
            depth=1)  # Equivalent to queue_size=1)

        # ROS 2 Subscriber
        self.subscription = self.create_subscription(Odometry,'payload/odom',self.odom_callback, qos_profile  )
        #Ros2 timer
        #self.create_timer(self.timer_period, timer_callback)

        # ROS 2 Publishers
        self.des_traj_pub = self.create_publisher(PositionCommand, 'payload/des_traj', qos_profile)
        self.cir_traj_status_pub = self.create_publisher(Header, 'payload/cir_traj_status', qos_profile)
        self.line_traj_status_pub = self.create_publisher(Header, 'payload/line_traj_status', qos_profile)
        self.min_der_traj_status_pub = self.create_publisher(Header, 'payload/min_der_traj_status', qos_profile)
        self.step_traj_status_pub = self.create_publisher(Header, 'payload/step_input_status', qos_profile)

        # ROS 2 Services
        self.circle_service = self.create_service(Circle, 'Circle', self.circle_traj_cb)
        self.circle_rot_service = self.create_service(CircleWithRotation, 'Circle_Rot_Rigidbody', self.circle_with_rot_body_traj_cb)
        self.line_service = self.create_service(Line, 'Line', self.line_traj_cb)
        self.min_derivative_line_service = self.create_service(Line, 'Min_Derivative_Line', self.min_derivative_line_traj_cb)
        self.step_pose_service = self.create_service(StepPose, 'Step_Pose', self.step_input_cb)

        self.get_logger().info("Trajectory Generator Initialization Finished")

    #def timer_callback(self):

    def circle_traj_cb(self, request, response):
        print("Generating circle............")
        if self.traj_start:
            self.is_finished = self.current_traj.finished
        if not self.is_finished:
            self.get_logger().info("Please wait for the previous trajectory to finish")
        else:
            self.current_traj = traj.traj()
            self.current_traj.circle(0, self.curr_pose[0:3], request.radius, request.tp, request.duration)
            self.time_reference = self.get_clock().now()
            self.traj_start = True
            status_msg = Header()
            status_msg.stamp = self.get_clock().now().to_msg()
            self.cir_traj_status_pub.publish(status_msg)
            
        response.success = True
        response.message = "Circle Trajectory Generated"
        return response

    def circle_with_rot_body_traj_cb(self, request, response):
        if self.traj_start:
            self.is_finished = self.current_traj.finished
        if not self.is_finished:
            self.get_logger().info("Please wait for the previous trajectory to finish")
        else:
            angle_amp = [request.angle_amp[0], request.angle_amp[1], request.angle_amp[2]]
            self.current_traj = traj.traj()
            self.current_traj.circlewithrotbody(0, self.curr_pose[0:7], request.radius, angle_amp, request.tp, request.duration)
            self.time_reference = self.get_clock().now()
            self.traj_start = True
            status_msg = Header()
            status_msg.stamp = self.get_clock().now().to_msg()
            self.cir_traj_status_pub.publish(status_msg)

        response.success = True
        response.message = "Circle Trajectory with Rotation Generated"
        return response

    def line_traj_cb(self, request, response):
        if self.traj_start:
            self.is_finished = self.current_traj.finished
        if not self.is_finished:
            self.get_logger().info("Please wait for the previous trajectory to finish")
        else:
            path = [[self.curr_pose[0], self.curr_pose[1], self.curr_pose[2]]]
            for pt in request.path:
                path.append([pt.x, pt.y, pt.z])
            self.current_traj = traj.traj()
            self.current_traj.line_quintic_traj(0, self.map, np.array(path))
            self.time_reference = self.get_clock().now()
            self.traj_start = True
            status_msg = Header()
            status_msg.stamp = self.get_clock().now().to_msg()
            self.line_traj_status_pub.publish(status_msg)

        response.success = True
        response.message = "Line Trajectory Generated"
        return response

    def min_derivative_line_traj_cb(self, request, response):
        if self.traj_start:
            self.is_finished = self.current_traj.finished
        if not self.is_finished:
            self.get_logger().info("Please wait for the previous trajectory to finish")
        else:
            path = [[self.curr_pose[0], self.curr_pose[1], self.curr_pose[2]]]
            for pt in request.path:
                path.append([pt.x, pt.y, pt.z])
            path = np.array(path)
            traj_constant = create_options.options()
            traj_constant.create_default_option(path.shape[0])
            self.current_traj = traj.traj()
            self.current_traj.min_snap_traj_generator(self, path, options=traj_constant)
            self.time_reference = self.get_clock().now()
            self.traj_start = True
            status_msg = Header()
            status_msg.stamp = self.get_clock().now().to_msg()
            self.min_der_traj_status_pub.publish(status_msg)

        response.success = True
        response.message = "Minimum Derivative Line Trajectory Generated"
        return response

    def step_input_cb(self, request, response):
        if self.traj_start:
            self.is_finished = self.current_traj.finished
        if not self.is_finished:
            self.get_logger().info("Please wait for the previous trajectory to finish")
        else:
            quat = rot.from_euler('ZYX', [request.yaw, request.pitch, request.roll], degrees=True).as_quat()
            pose = np.array([request.position[0], request.position[1], request.position[2], quat[3], quat[0], quat[1], quat[2]])
            self.current_traj = traj.traj()
            self.current_traj.step_des(0, pose)
            self.time_reference = self.get_clock().now()
            self.traj_start = True
            status_msg = Header()
            status_msg.stamp = self.get_clock().now().to_msg()
            self.step_traj_status_pub.publish(status_msg)

        response.success = True
        response.message = "Step Pose Called"
        return response

    def odom_callback(self, msg):
        self.curr_pose = np.array([
            msg.pose.pose.position.x, msg.pose.pose.position.y, msg.pose.pose.position.z,
            msg.pose.pose.orientation.w, msg.pose.pose.orientation.x, msg.pose.pose.orientation.y, msg.pose.pose.orientation.z
        ])        
        self.send_des_traj(self.get_clock().now())

    def send_des_traj(self, t):
        # DESCRIPTION
        # when called, will spit out a new waypoint for the current trajectory type. 
        # Must be call after initialization of each type of trajectory

        # INPUT
        # t  		- float, current simulation time

        # OUTPUT
        # /			- publish PositionCommand type message to payload/des_traj

        if self.traj_start:
            if self.current_traj.traj_type != 0:
                if self.current_traj.traj_type == 1:
                    self.current_traj.circle(t - self.time_reference)
                    if not self.current_traj.finished:
                        status_msgs = Header()
                        status_msgs.stamp = self.get_clock().now().to_msg()
                        self.cir_traj_status_pub.publish(status_msgs)
                elif self.current_traj.traj_type == 2:
                    self.current_traj.circlewithrotbody(t - self.time_reference)
                    if not self.current_traj.finished:
                        status_msgs = Header()
                        status_msgs.stamp = self.get_clock().now().to_msg()
                        self.cir_traj_status_pub.publish(status_msgs)
                elif self.current_traj.traj_type == 3:
                    self.current_traj.line_quintic_traj(t - self.time_reference)
                    if not self.current_traj.finished:
                        status_msgs = Header()
                        status_msgs.stamp = self.get_clock().now().to_msg()
                        self.line_traj_status_pub.publish(status_msgs)
                elif self.current_traj.traj_type == 4:
                    self.current_traj.min_snap_traj_generator(t - self.time_reference)
                    if not self.current_traj.finished:
                        status_msgs = Header()
                        status_msgs.stamp = self.get_clock().now().to_msg()
                        self.min_der_traj_status_pub.publish(status_msgs)
                elif self.current_traj.traj_type == 5:
                    self.current_traj.step_des(t - self.time_reference)
                    if not self.current_traj.finished:
                        status_msgs = Header()
                        status_msgs.stamp = self.get_clock().now().to_msg()
                        self.step_traj_status_pub.publish(status_msgs)

                # Publish the command
                now = self.get_clock().now().to_msg()
                
                message = PositionCommand()
                message.header.stamp = now
                message.position.x = self.current_traj.state_struct["pos_des"][0]
                message.position.y = self.current_traj.state_struct["pos_des"][1]
                message.position.z = self.current_traj.state_struct["pos_des"][2]
                message.velocity.x = self.current_traj.state_struct["vel_des"][0]
                message.velocity.y = self.current_traj.state_struct["vel_des"][1]
                message.velocity.z = self.current_traj.state_struct["vel_des"][2]
                message.acceleration.x = self.current_traj.state_struct["acc_des"][0]
                message.acceleration.y = self.current_traj.state_struct["acc_des"][1]
                message.acceleration.z = self.current_traj.state_struct["acc_des"][2]
                message.jerk.x = self.current_traj.state_struct["jrk_des"][0]
                message.jerk.y = self.current_traj.state_struct["jrk_des"][1]
                message.jerk.z = self.current_traj.state_struct["jrk_des"][2]
                #print(type(self.current_traj.state_struct["quat_des"][0]))
                message.quaternion.w = self.current_traj.state_struct["quat_des"][0]
                message.quaternion.x = self.current_traj.state_struct["quat_des"][1]
                message.quaternion.y = self.current_traj.state_struct["quat_des"][2]
                message.quaternion.z = self.current_traj.state_struct["quat_des"][3]
                message.angular_velocity.x = self.current_traj.state_struct["omega_des"][0]
                message.angular_velocity.y = self.current_traj.state_struct["omega_des"][1]
                message.angular_velocity.z = self.current_traj.state_struct["omega_des"][2]
                # fig = plt.figure()
                # ax = fig.ass_sub_plot(111, projection = '3d')
                # ax.plot(message.position.x, message.position.y, message.position.z)
                # plt.savefig("trajplot")
                

                self.des_traj_pub.publish(message)


def main(args=None):
    rclpy.init(args=args)
    node = TrajNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
