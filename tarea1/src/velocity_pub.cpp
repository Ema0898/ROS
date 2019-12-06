#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <turtlesim/Pose.h>

#include <sstream>

int pose_x;

void velocityCallback(const turtlesim::PoseConstPtr& pose)
{
  pose_x = pose->x;  
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "velocity_talker");
  
  ros::NodeHandle n;

  ros::Publisher chatter_pub = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 1000);
  ros::Subscriber sub = n.subscribe("/turtle1/pose", 1000, velocityCallback);

  ros::Rate loop_rate(1.0);
 
  int linear_x = 2;
  int count_angular_z = 0;

  bool backwards = true;
  while (ros::ok())
  {    
    geometry_msgs::Twist msg;
    std::stringstream ss;

    ss << pose_x;

    msg.linear.x = linear_x;
    msg.angular.z = count_angular_z % 7;

    ROS_INFO("Turtle position %s\n", ss.str().c_str());

    if (pose_x >= 11 && linear_x == 2) 
    {
      backwards = false;
      ++count_angular_z;    
    }

    if (pose_x <= 0 && linear_x == -2) 
    {
      backwards = true;
      ++count_angular_z;
    } 

    if (backwards)
    {
      linear_x = 2;        
    }
    else
    {
      linear_x = -2;
    }   

    chatter_pub.publish(msg);

    ros::spinOnce();
    loop_rate.sleep();     
  }


  return 0;
}