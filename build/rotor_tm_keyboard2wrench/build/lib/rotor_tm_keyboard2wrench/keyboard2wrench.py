#!/usr/bin/env python

import numpy as np
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Wrench
from geometry_msgs.msg import WrenchStamped
import threading
import time

import sys
import termios
import tty

if sys.platform == 'win32':
    import msvcrt
else:
    import termios
    import tty

WrenchMsg = Wrench

msg = """
Reading from the keyboard and Publishing to Wrench!
---------------------------
Increase Force:
   1,2,3,4,5,6
Decrease Force:
   q,w,e,r,t,y

CTRL-C to quit
"""

moveBindings = {
    '1': (0.1, 0, 0, 0, 0, 0),
    '2': (0, 0.025, 0, 0, 0, 0),
    '3': (0, 0, 0.025, 0, 0, 0),
    '4': (0, 0, 0, 0.01, 0, 0),
    '5': (0, 0, 0, 0, 0.01, 0),
    '6': (0, 0, 0, 0, 0, 0.01),
    'q': (-0.1, 0, 0, 0, 0, 0),
    'w': (0, -0.025, 0, 0, 0, 0),
    'e': (0, 0, -0.025, 0, 0, 0),
    'r': (0, 0, 0, -0.01, 0, 0),
    't': (0, 0, 0, 0, -0.01, 0),
    'y': (0, 0, 0, 0, 0, -0.01),
}

speedBindings = {
    'q': (1.1, 1.1),
    'z': (.9, .9),
    'w': (1.1, 1),
    'x': (.9, 1),
    'e': (1, 1.1),
    'c': (1, .9),
}

class PublishThread(threading.Thread):
    def __init__(self,rate,node, stamped, twist_frame):
        super(PublishThread,self).__init__()
        self.publisher = node.create_publisher(Wrench,'/payload/so3_control/ext_wrench',10)
        self.x     = 0.0
        self.y     = 0.0
        self.z     = 0.0
        self.yaw   = 0.0
        self.roll  = 0.0
        self.pitch = 0.0
        self.speed = 1
        self.condition = threading.Condition()
        self.done = False
        self.stamped = stamped
        self.twist_frame = twist_frame

        # Set timeout to None if rate is 0 (causes new_message to wait forever)
        if rate != 0.0:
            self.timeout = 1.0 / rate
        else:
            self.timeout = None

        self.start()

    def wait_for_subscribers(self):
        i = 0
        while rclpy.ok() and self.publisher.get_subscription_count() == 0:
            if i == 4:
                self.node.get_logger().info(f"Waiting for subscriber to connect to {self.publisher.topic}")
            time.sleep(0.5)
            i += 1
            i = i%5
        if not rclpy.ok():
            raise Exception("Got shutdown request before subscribers connected")
        
    def update(self,x,y,z,yaw,roll,pitch):
        self.condition.acquire()
        self.x += x
        self.y += y
        self.z += z
        self.yaw   += yaw
        self.roll  += roll
        self.pitch += pitch
        # Notify publish thread that we have a new message.
        self.condition.notify()
        self.condition.release()

    def stop(self):
        self.done = True
        self.update(0,0,0,0,0,0)
        self.join()

    def run(self):
        wrench_msg = Wrench()

        # If we are using stamped messages (i.e., including a timestamp and frame ID)
        if self.stamped:
            wrench = wrench_msg
            wrench_msg.header.stamp    = self.node.get_clock().now().to_msg() # Using ROS2 clock
            wrench_msg.header.frame_id = self.twist_frame
        else:
            wrench_msg = wrench_msg

        while not self.done:
            if self.stamped:
                wrench_msg.header.stamp = self.node.get_clock().now().to_msg()
            self.condition.acquire()
            # wait for a new message or timeout
            self.condition.wait(self.timeout)

            # Copy state into wrench message
            wrench_msg.force.x = self.x * self.speed
            wrench_msg.force.y = self.y * self.speed
            wrench_msg.force.z = self.z * self.speed
            wrench_msg.torque.x = self.yaw * self.speed
            wrench_msg.torque.y = self.roll * self.speed
            wrench_msg.torque.z = self.pitch * self.speed
            
            # Publish
            self.publisher.publish(wrench_msg)

        # Publish stop message when thread exits
        wrench_msg.force.x = float(0)
        wrench_msg.force.y = float(0)
        wrench_msg.force.z = float(0)
        wrench_msg.torque.x = float(0)
        wrench_msg.torque.y = float(0)
        wrench_msg.torque.z = float(0)
        self.publisher.publish(wrench_msg)


def getKey(settings):
    if sys.platform == 'win32':
        key = msvcrt.getwch()
    else:
        tty.setraw(sys.stdin.fileno())
        key = sys.stdin.read(1)
        termios.tcsetattr(sys.stdin, termios.TCSADRAIN, settings)
    return key

def saveTerminalSettings():
    if sys.platform == 'win32':
        return None
    return termios.tcgetattr(sys.stdin)

def restoreTerminalSettings(old_settings):
    if sys.platform == 'win32':
        return
    termios.tcsetattr(sys.stdin, termios.TCSADRAIN, old_settings)

def check(x, y, z, yaw, roll, pitch):
    return "x %s\ty %s \tz %s\troll %s \tpitch %s \tyaw %s" % (
        np.around(x, 3), np.around(y, 3), np.around(z, 3), 
        np.around(yaw, 3), np.around(roll, 3), np.around(pitch, 3))

def main(args=None):
    print("in the main")
    settings = saveTerminalSettings()

    rclpy.init(args=args)
    node = rclpy.create_node('teleop_wrench_keyboard')

    speed = node.declare_parameter("speed", 0.5)
    turn = node.declare_parameter("turn", 1.0)
    repeat = node.declare_parameter("repeat_rate", 100)
    key_timeout = node.declare_parameter("key_timeout", 0.0)
    stamped = node.declare_parameter("stamped", False)
    twist_frame = node.declare_parameter("frame_id", '')

    # Now get the parameter values
    speed = speed.get_parameter_value().double_value
    turn = turn.get_parameter_value().double_value
    repeat = repeat.get_parameter_value().integer_value
    key_timeout = key_timeout.get_parameter_value().double_value
    stamped = stamped.get_parameter_value().bool_value
    twist_frame = twist_frame.get_parameter_value().string_value

    # speed = node.declare_parameter("speed", 0.5).get_parameter_value().double_value
    # turn = node.declare_parameter("turn", 1.0).get_parameter_value().double_value
    # repeat = node.declare_parameter("repeat_rate", 100).get_parameter_value().integer_value
    # key_timeout = node.declare_parameter("key_timeout", 0.0).get_parameter_value().double_value
    # stamped = node.declare_parameter("stamped", False).get_parameter_value().bool_value
    # twist_frame = node.declare_parameter("frame_id", '').get_parameter_value().string_value

    if stamped:
        TwistMsg = WrenchStamped
    if key_timeout == 0.0:
        key_timeout = None

    pub_thread = PublishThread(rate = repeat, node = node, stamped = stamped, twist_frame = twist_frame)
    # publisher = node.create_publisher(WrenchMsg, '/payload/so3_control/ext_wrench', 10)

    x = 0
    y = 0
    z = 0
    yaw = 0
    roll = 0
    pitch = 0
    status = 0

    try:
        print("here in the loop")
        pub_thread.wait_for_subscribers()
        pub_thread.update(x, y, z, yaw, roll, pitch)

        print(msg)

        while rclpy.ok():
            key = getKey(settings)
            if key in moveBindings.keys():
                x = moveBindings[key][0]
                y = moveBindings[key][1]
                z = moveBindings[key][2]
                yaw = moveBindings[key][3]
                roll = moveBindings[key][4]
                pitch = moveBindings[key][5]
            elif key in speedBindings.keys():
                speed = speed * speedBindings[key][0]
                turn = turn * speedBindings[key][1]

                if (status == 14):
                    print(msg)
                status = (status + 1) % 15
            else:
                if key == '' and x == 0 and y == 0 and z == 0:
                    continue
                x = 0
                y = 0
                z = 0
                if key == '\x03':
                    break
            
            pub_thread.update(x, y, z, yaw, roll, pitch)

            # Create a Wrench message
            # wrench_msg = WrenchMsg()
            # wrench_msg.force.x = x * speed
            # wrench_msg.force.y = y * speed
            # wrench_msg.force.z = z * speed
            # wrench_msg.torque.x = yaw * speed
            # wrench_msg.torque.y = roll * speed
            # wrench_msg.torque.z = pitch * speed

            # Publish the message
            # publisher.publish(wrench_msg)

            # Print the current state
            print(check(pub_thread.x, pub_thread.y, pub_thread.z, pub_thread.yaw, pub_thread.roll, pub_thread.pitch))

    except Exception as e:
        print("Error occurred:", e)

    finally:
        pub_thread.stop()
        restoreTerminalSettings(settings)
        # node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
