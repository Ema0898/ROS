#include <ros/ros.h>
#include <pub_sub_tutorial/AddTwoInts.h>

bool add(pub_sub_tutorial::AddTwoInts::Request &req, pub_sub_tutorial::AddTwoInts::Response &res) 
{
    res.sum = req.a + req.b;
    ROS_INFO("Request: x = %ld, y = %ld", (long int) req.a, (long int) req.b);
    ROS_INFO("Sending back response: [%ld]", (long int) res.sum);
    return true;  
}

int main(int argc, char **argv) 
{
    ros::init(argc, argv, "add_two_ints_server");
    ros::NodeHandle n;

    ros::ServiceServer service = n.advertiseService("add_two_ints", add);
    ROS_INFO("Ready to add two ints.");
    ros::spin();

    return 0;
}