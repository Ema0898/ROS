#!/usr/bin/env python
# license removed for brevity
import rospy
import math
from turtlesim.msg import Pose
from geometry_msgs.msg import Twist

x = 0
y = 0

def callback(pose):
    global x, y

    x = pose.x
    y = pose.y

def main():
    pub = rospy.Publisher("/turtle1/cmd_vel", Twist, queue_size=10)
    rospy.Subscriber("/turtle1/pose", Pose, callback)

    rospy.init_node('talker', anonymous=True)
    rate = rospy.Rate(10) # 10hz

    velocity_msg = Twist()
    velocity_msg.linear.x = 1

    distance_moved = 0
    distance = 20

    x0 = x
    y0 = y

    while not rospy.is_shutdown():
        pub.publish(velocity_msg)

        distance_moved = distance_moved + abs(0.5 * math.sqrt(((x - x0) ** 2) + ((y - y0) ** 2)))
        print(distance_moved)

        if  not (distance_moved < distance):
            rospy.loginfo("reached")
            break

        rate.sleep()
    
    velocity_msg.linear.x = 0
    pub.publish(velocity_msg)

    rospy.spin()

if __name__ == '__main__':
    try:
        main()
    except rospy.ROSInterruptException:
        pass