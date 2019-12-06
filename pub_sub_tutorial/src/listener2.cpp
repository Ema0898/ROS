#include "ros/ros.h"
#include <pub_sub_tutorial/IoTSensor.h>

#include <sstream>

void chatterCallback(const pub_sub_tutorial::IoTSensor& msg)
{
  std::stringstream ss;
  ss << msg.id << ", " << msg.name << ", " << msg.temperature << ", " << msg.humidity;

  ROS_INFO("I heard: [%s]", ss.str().c_str());
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "listener");

  ros::NodeHandle n;

  ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);
 
  ros::spin();

  return 0;
}

