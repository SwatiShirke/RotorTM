import rclpy
from rclpy.node import Node
from nav_msgs.msg import Odometry
from rotor_tm_msgs.msg import FMNCommand, TrajCommand, PositionCommand
import rosbag2_py
from rclpy.qos import QoSProfile, QoSReliabilityPolicy, QoSHistoryPolicy
import shutil
import os

class BagWriterNode(Node):
    def __init__(self):
        super().__init__('bag_writer_node')

        # Initialize ROS bag writer
        self.bag_writer = rosbag2_py.SequentialWriter()

        # Bag file directory and cleanup if needed
        bag_dir = "multi_topic_bag"
        if os.path.exists(bag_dir):
            self.get_logger().info(f"Removing existing directory: {bag_dir}")
            shutil.rmtree(bag_dir)  # Remove existing directory

        # Set storage options (bag file path and storage format)
        storage_options = rosbag2_py.StorageOptions(
            uri='multi_topic_bag',  # Folder name for the bag file
            storage_id='sqlite3'
        )
        converter_options = rosbag2_py.ConverterOptions(
            input_serialization_format='cdr',
            output_serialization_format='cdr'
        )
        self.bag_writer.open(storage_options, converter_options)

        # Create topics for saving messages
        self.create_bag_topic('payload/odom', 'nav_msgs/msg/Odometry')
        self.create_bag_topic('payload/pl_nmpc_FMN_cmd', 'rotor_tm_msgs/msg/FMNCommand')
        self.create_bag_topic('payload/des_traj_n', 'rotor_tm_msgs/msg/TrajCommand')

        # Subscriptions
        qos_profile = QoSProfile(
            reliability=QoSReliabilityPolicy.BEST_EFFORT,  # Best effort, similar to TCP no delay
            history=QoSHistoryPolicy.KEEP_LAST,
            depth=1  # Equivalent to queue_size=1)
        )
        self.create_subscription(Odometry, "payload/odom", self.odom_callback, qos_profile)
        self.create_subscription(FMNCommand, "payload/pl_nmpc_FMN_cmd", self.control_input_callback, qos_profile)
        self.create_subscription(TrajCommand, "payload/des_traj_n", self.desired_traj_callback, qos_profile)

    def create_bag_topic(self, topic_name, type_name):
        """Create a topic in the ROS bag."""
        self.bag_writer.create_topic(
            rosbag2_py.TopicMetadata(
                name=topic_name,
                type=type_name,
                serialization_format='cdr'
            )
        )
        self.get_logger().info(f"Created topic: {topic_name}")

    def odom_callback(self, msg):
        """Handle odometry messages."""
        self.get_logger().info(f"Received Odometry message")
        self.write_to_bag('payload/odom', msg)

    def control_input_callback(self, msg):
        """Handle control input messages."""
        self.get_logger().info(f"Received FMNCommand message")
        self.write_to_bag('payload/pl_nmpc_FMN_cmd', msg)

    def desired_traj_callback(self, msg):
        """Handle reference trajectory messages."""
        if len(msg.points) > 0:  # Ensure there is at least one point in the trajectory
            # Get the 0th point (first point)
            first_point = msg.points[0]
            self.get_logger().info(f"Received TrajCommand message with first point: {first_point}")
            self.write_to_bag('payload/des_traj_n', msg)  # Save the entire TrajCommand message (or just the first point if needed)

    def write_to_bag(self, topic_name, message):
        """Write a message to the ROS bag."""
        self.get_logger().info(f"Writing message to topic: {topic_name}")
        self.bag_writer.write(
            topic_name,
            self.serialize_message(message),
            self.get_clock().now().nanoseconds
        )

    def serialize_message(self, message):
        """Serialize a ROS message."""
        from rclpy.serialization import serialize_message
        return serialize_message(message)

    def destroy(self):
        """Ensure the bag writer is properly closed."""
        self.get_logger().info("Closing bag writer")
        self.bag_writer.reset()
        super().destroy_node()


def main(args=None):
    rclpy.init(args=args)
    node = BagWriterNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
