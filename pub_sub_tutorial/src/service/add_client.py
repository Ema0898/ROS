#!/usr/bin/env python

import sys
import rospy
from pub_sub_tutorial.srv import AddTwoInts
from pub_sub_tutorial.srv import AddTwoIntsRequest
from pub_sub_tutorial.srv import AddTwoIntsResponse

def add_two_ints_client(x, y):
    rospy.wait_for_service('add_two_ints')
    try:
        add_two_ints = rospy.ServiceProxy('add_two_ints', AddTwoInts)
        resp1 = add_two_ints(x, y)
        return resp1.sum
    except rospy.ServiceException, e:
        print("Service call failed: {}".format(e))

def usage():
    return "{} [x y]".format(sys.argv[0])

if __name__ == "__main__":
    if len(sys.argv) == 3:
        x = int(sys.argv[1])
        y = int(sys.argv[2])
    else:
        print(usage())
        sys.exit(1)
    print("Requesting {} + {}".format(x, y))
    print("{} + {} = {}".format(x, y, add_two_ints_client(x, y)))