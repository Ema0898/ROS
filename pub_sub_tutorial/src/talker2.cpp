#include <ros/ros.h>
#include <pub_sub_tutorial/IoTSensor.h>

#include <sstream>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "talker");
 
  ros::NodeHandle n;
  ros::Publisher chatter_pub = n.advertise<pub_sub_tutorial::IoTSensor>("chatter", 1000);

  ros::Rate loop_rate(1.0);
  
  while (ros::ok())
  {
    pub_sub_tutorial::IoTSensor msg;

    msg.id = 1;
    msg.name = "iot_parking_01";
    msg.temperature = 24.33;
    msg.humidity = 35.56;

    std::stringstream ss;
    ss << msg.id << ", " << msg.name << ", " << msg.temperature << ", " << msg.humidity;

    ROS_INFO("[Talker] I published %s\n", ss.str().c_str());

    chatter_pub.publish(msg);

    ros::spinOnce();
    loop_rate.sleep();
  }

  return 0;
}
