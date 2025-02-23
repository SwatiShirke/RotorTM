import rclpy
from rclpy.node import Node
from rclpy.serialization import serialize_message
from rclpy.qos import QoSProfile, ReliabilityPolicy, HistoryPolicy, DurabilityPolicy
from visualization_msgs.msg import MarkerArray
from tf2_ros.buffer import Buffer
from tf2_ros.transform_listener import TransformListener
from geometry_msgs.msg import TransformStamped
from tf2_msgs.msg import TFMessage
import rosbag2_py
import yaml  # ✅ Import YAML parser
import shutil
import os

class DataSaver(Node):
    def __init__(self):
        super().__init__('data_saver')

        # Bag directory name
        bag_name = 'marker_data'

        # Remove existing rosbag to prevent overwrite errors
        if os.path.exists(bag_name):
            self.get_logger().info(f"Deleting old rosbag: {bag_name}")
            shutil.rmtree(bag_name)

        # Setup ROS2 Bag Writer
        self.bag_writer = rosbag2_py.SequentialWriter()

        # Storage options (SQLite3 database for rosbag2)
        storage_options = rosbag2_py.StorageOptions(
            uri=bag_name,
            storage_id='sqlite3'
        )

        # Converter options
        converter_options = rosbag2_py.ConverterOptions(
            input_serialization_format='cdr',
            output_serialization_format='cdr'
        )

        # Open the bag writer
        self.bag_writer.open(storage_options, converter_options)

        # Create topics in the rosbag
        marker_topic = rosbag2_py.TopicMetadata(
            name='system/marker',
            type='visualization_msgs/msg/MarkerArray',
            serialization_format='cdr'
        )
        tf_static_topic = rosbag2_py.TopicMetadata(
            name='/tf_static',
            type='tf2_msgs/msg/TFMessage',
            serialization_format='cdr'
        )

        self.bag_writer.create_topic(marker_topic)
        self.bag_writer.create_topic(tf_static_topic)

        self.get_logger().info("Recording MarkerArray and Static Transforms into rosbag...")

        # ✅ Initialize TF buffer and listener
        self.tf_buffer = Buffer()
        self.tf_listener = TransformListener(self.tf_buffer, self)

        # ✅ Subscribe to MarkerArray (TFs will be saved alongside markers)
        self.subscription_marker = self.create_subscription(
            MarkerArray,
            'system/marker',
            self.marker_callback,
            10
        )

        self.get_logger().info("Subscribed to /system/marker and fetching transforms from buffer")

    def marker_callback(self, msg):
        """ Callback for MarkerArray messages, stores markers and transforms in the rosbag """
        try:
            # ✅ Save MarkerArray to rosbag
            serialized_msg = serialize_message(msg)
            timestamp_ns = self.get_clock().now().nanoseconds
            self.bag_writer.write('system/marker', serialized_msg, timestamp_ns)
            self.get_logger().info("Stored MarkerArray message in rosbag.")

            # ✅ Fetch and store latest static transforms
            self.store_tf_static()

        except Exception as e:
            self.get_logger().error(f"Failed to store MarkerArray or transforms: {str(e)}")

    def store_tf_static(self):
        """ Fetches static transforms from TF buffer and saves them to the rosbag """
        try:
            # ✅ Get all frames stored in the TF buffer (Parse YAML correctly)
            transform_yaml = self.tf_buffer.all_frames_as_yaml()
            transform_dict = yaml.safe_load(transform_yaml)  # ✅ Convert YAML to dictionary

            if not transform_dict:
                self.get_logger().warning("No static transforms available in TF buffer yet.")
                return

            tf_message = TFMessage()

            # ✅ Convert stored transforms to TFMessage format
            for frame_id in transform_dict.keys():  # ✅ Only use valid frame IDs
                try:
                    transform = self.tf_buffer.lookup_transform('map', frame_id, rclpy.time.Time())
                    tf_message.transforms.append(transform)
                except Exception as e:
                    self.get_logger().warning(f"Skipping frame {frame_id}, error: {str(e)}")

            # ✅ Store TFMessage in rosbag
            if tf_message.transforms:
                serialized_msg = serialize_message(tf_message)
                timestamp_ns = self.get_clock().now().nanoseconds
                self.bag_writer.write('/tf_static', serialized_msg, timestamp_ns)
                self.get_logger().info("Stored Static Transforms in rosbag.")

        except Exception as e:
            self.get_logger().error(f"Failed to retrieve and store static transforms: {str(e)}")

    def cleanup(self):
        """ Cleanup function to ensure proper shutdown """
        self.get_logger().info("Shutting down node, closing rosbag writer...")
        self.bag_writer = None

def main(args=None):
    rclpy.init(args=args)
    node = DataSaver()

    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.cleanup()
    finally:
        node.cleanup()
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
