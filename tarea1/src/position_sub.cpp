#include <ros/ros.h>
#include <turtlesim/Pose.h>

#include <sstream>

void chatterCallback(const turtlesim::PoseConstPtr& pose)
{
  std::stringstream x_str;
  std::stringstream y_str;
  std::stringstream theta_str;

  x_str << pose->x;
  y_str << pose->y;
  theta_str << pose->theta;

  ROS_INFO("Turtle position x: %s, y: %s, theta: %s", 
  x_str.str().c_str(), y_str.str().c_str(), theta_str.str().c_str());
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "pose_listener");

  ros::NodeHandle n;

  ros::Subscriber sub = n.subscribe("/turtle1/pose", 1000, chatterCallback);
 
  ros::spin();
  
  return 0;
}
