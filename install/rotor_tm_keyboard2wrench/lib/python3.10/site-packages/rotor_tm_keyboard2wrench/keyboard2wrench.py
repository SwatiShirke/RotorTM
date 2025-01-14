#!/usr/bin/env python

import numpy as np
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Wrench

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

    speed = node.declare_parameter("speed", 0.5).get_parameter_value().double_value
    turn = node.declare_parameter("turn", 1.0).get_parameter_value().double_value
    repeat = node.declare_parameter("repeat_rate", 100).get_parameter_value().integer_value
    key_timeout = node.declare_parameter("key_timeout", 0.0).get_parameter_value().double_value
    stamped = node.declare_parameter("stamped", False).get_parameter_value().bool_value
    twist_frame = node.declare_parameter("frame_id", '').get_parameter_value().string_value

    if key_timeout == 0.0:
        key_timeout = None

    publisher = node.create_publisher(WrenchMsg, '/payload/so3_control/ext_wrench', 10)

    x = 0
    y = 0
    z = 0
    yaw = 0
    roll = 0
    pitch = 0
    status = 0

    try:
        print("here in the loop")
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

            # Create a Wrench message
            wrench_msg = WrenchMsg()
            wrench_msg.force.x = x * speed
            wrench_msg.force.y = y * speed
            wrench_msg.force.z = z * speed
            wrench_msg.torque.x = yaw * speed
            wrench_msg.torque.y = roll * speed
            wrench_msg.torque.z = pitch * speed

            # Publish the message
            publisher.publish(wrench_msg)

            # Print the current state
            print(check(x, y, z, yaw, roll, pitch))

    except Exception as e:
        print("Error occurred:", e)

    finally:
        restoreTerminalSettings(settings)
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
