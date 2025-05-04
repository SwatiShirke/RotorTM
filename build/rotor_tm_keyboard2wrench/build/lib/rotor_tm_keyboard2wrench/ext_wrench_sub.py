#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Wrench
from geometry_msgs.msg import TwistStamped


class ListenerNode(Node):
    def __init__(self):
        super().__init__('listener')

        # Create a subscription to the topic '/payload/so3_control/ext_wrench'
        self.subscription = self.create_subscription(
            Wrench,
            '/payload/so3_control/ext_wrench',
            self.callback,
            10  # QoS (Quality of Service) depth
        )

        self.get_logger().info("Listener node has been started.")

    def callback(self, data):
        # Callback function to process incoming data
        self.get_logger().info(f"x: {data.force.x}")
        self.get_logger().info(f"y: {data.force.y}")
        self.get_logger().info(f"z: {data.force.z}")
        self.get_logger().info(f"pitch: {data.torque.x}")
        self.get_logger().info(f"roll: {data.torque.y}")
        self.get_logger().info(f"yaw: {data.torque.z}")


def main():
    rclpy.init()

    listener_node = ListenerNode()

    # Spin to keep the node active and process callbacks
    rclpy.spin(listener_node)

    # Shutdown ROS2 when the node is stopped
    listener_node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
