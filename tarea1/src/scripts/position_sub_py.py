#!/usr/bin/env python
import rospy
from turtlesim.msg import Pose

def callback(pose):
    rospy.loginfo(rospy.get_caller_id() + "Turtle x: %d", pose.x)
    rospy.loginfo(rospy.get_caller_id() + "Turtle y: %d", pose.y)
    rospy.loginfo(rospy.get_caller_id() + "Turtle theta: %d", pose.theta)
    
def listener():

    rospy.init_node('pose_listener_py', anonymous=True)

    rospy.Subscriber("/turtle1/pose", Pose, callback)

    rospy.spin()

if __name__ == '__main__':
    listener()