import rosbag2_py
import matplotlib.pyplot as plt
from rclpy.serialization import deserialize_message
from nav_msgs.msg import Odometry
from rotor_tm_msgs.msg import FMNCommand, TrajCommand


def read_bag_data(bag_path):
    reader = rosbag2_py.SequentialReader()
    storage_options = rosbag2_py.StorageOptions(uri=bag_path, storage_id='sqlite3')
    converter_options = rosbag2_py.ConverterOptions(input_serialization_format='cdr', output_serialization_format='cdr')
    reader.open(storage_options, converter_options)

    topics = ['payload/odom', 'payload/pl_nmpc_FMN_cmd', 'payload/des_traj_n']
    topic_data = {topic: [] for topic in topics}

    while reader.has_next():
        (topic_name, serialized_msg, t) = reader.read_next()
        if topic_name in topics:
            if topic_name == 'payload/odom':
                msg = deserialize_message(serialized_msg, Odometry)
                topic_data[topic_name].append((t, msg.pose.pose.position.x, msg.pose.pose.position.y, msg.pose.pose.position.z,
                                               msg.twist.twist.linear.x, msg.twist.twist.linear.y, msg.twist.twist.linear.z))
            elif topic_name == 'payload/pl_nmpc_FMN_cmd':
                msg = deserialize_message(serialized_msg, FMNCommand)
                topic_data[topic_name].append((t, msg.rlink_thrust.x, msg.rlink_thrust.y, msg.rlink_thrust.z,
                                               msg.moments.x, msg.moments.y, msg.moments.z))
            elif topic_name == 'payload/des_traj_n':
                msg = deserialize_message(serialized_msg, TrajCommand)
                if len(msg.points) > 0:
                    first_point = msg.points[0]
                    topic_data[topic_name].append((t, first_point.position.x, first_point.position.y, first_point.position.z,
                                                   first_point.velocity.x, first_point.velocity.y, first_point.velocity.z))

    return topic_data


def plot_data(topic_data):
    # Plot odometry and reference trajectory (x vs. t)
    if 'payload/odom' in topic_data and 'payload/des_traj_n' in topic_data:
        # Odometry data
        odom_times, odom_x, odom_y, odom_z, odom_vx, odom_vy, odom_vz = zip(*topic_data['payload/odom'])
        # Reference trajectory data
        traj_times, traj_x, traj_y, traj_z, traj_vx, traj_vy, traj_vz = zip(*topic_data['payload/des_traj_n'])

        # Plot X position
        plt.figure()
        plt.plot(odom_times, odom_x, label='Odometry X')
        plt.plot(traj_times, traj_x, label='Reference Trajectory X', linestyle='--')
        plt.legend()
        plt.xlabel('Time')
        plt.ylabel('X Position')
        plt.title('Odometry vs Reference Trajectory X')
        
        # Plot Y position
        plt.figure()
        plt.plot(odom_times, odom_y, label='Odometry Y')
        plt.plot(traj_times, traj_y, label='Reference Trajectory Y', linestyle='--')
        plt.legend()
        plt.xlabel('Time')
        plt.ylabel('Y Position')
        plt.title('Odometry vs Reference Trajectory Y')

        # Plot Z position
        plt.figure()
        plt.plot(odom_times, odom_z, label='Odometry Z')
        plt.plot(traj_times, traj_z, label='Reference Trajectory Z', linestyle='--')
        plt.legend()
        plt.xlabel('Time')
        plt.ylabel('Z Position')
        plt.title('Odometry vs Reference Trajectory Z')

        # Plot X velocity
        plt.figure()
        plt.plot(odom_times, odom_vx, label='Odometry Vx')
        plt.plot(traj_times, traj_vx, label='Reference Trajectory Vx', linestyle='--')
        plt.legend()
        plt.xlabel('Time')
        plt.ylabel('X Velocity')
        plt.title('Odometry vs Reference Trajectory Vx')

        # Plot Y velocity
        plt.figure()
        plt.plot(odom_times, odom_vy, label='Odometry Vy')
        plt.plot(traj_times, traj_vy, label='Reference Trajectory Vy', linestyle='--')
        plt.legend()
        plt.xlabel('Time')
        plt.ylabel('Y Velocity')
        plt.title('Odometry vs Reference Trajectory Vy')

        # Plot Z velocity
        plt.figure()
        plt.plot(odom_times, odom_vz, label='Odometry Vz')
        plt.plot(traj_times, traj_vz, label='Reference Trajectory Vz', linestyle='--')
        plt.legend()
        plt.xlabel('Time')
        plt.ylabel('Z Velocity')
        plt.title('Odometry vs Reference Trajectory Vz')

    # Plot control input (force and moments)
    if 'payload/pl_nmpc_FMN_cmd' in topic_data:
        times, rlink_thrust_x, rlink_thrust_y, rlink_thrust_z, moments_x, moments_y, moments_z = zip(*topic_data['payload/pl_nmpc_FMN_cmd'])
        
        # Plot RLink Thrust X
        plt.figure()
        plt.plot(times, rlink_thrust_x, label='Thrust X')
        plt.xlabel('Time')
        plt.ylabel('Force X')
        plt.title('Force X over Time')

        # Plot RLink Thrust Y
        plt.figure()
        plt.plot(times, rlink_thrust_y, label='Thrust Y')
        plt.xlabel('Time')
        plt.ylabel('Force Y')
        plt.title('Force Y over Time')

        # Plot RLink Thrust Z
        plt.figure()
        plt.plot(times, rlink_thrust_z, label='Thrust Z')
        plt.xlabel('Time')
        plt.ylabel('Force Z')
        plt.title('Force Z over Time')

        # Plot Moments X
        plt.figure()
        plt.plot(times, moments_x, label='Moments X')
        plt.xlabel('Time')
        plt.ylabel('Moments X')
        plt.title('Moments X over Time')

        # Plot Moments Y
        plt.figure()
        plt.plot(times, moments_y, label='Moments Y')
        plt.xlabel('Time')
        plt.ylabel('Moments Y')
        plt.title('Moments Y over Time')

        # Plot Moments Z
        plt.figure()
        plt.plot(times, moments_z, label='Moments Z')
        plt.xlabel('Time')
        plt.ylabel('Moments Z')
        plt.title('Moments Z over Time')

    plt.legend()
    plt.show()


# Read and plot the data
bag_path = '/home/swati/Quad_DR/RotorTM/multi_topic_bag'
data = read_bag_data(bag_path)
plot_data(data)
