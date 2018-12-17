#include "ros/ros.h"
#include "std_msgs/String.h"
#include <iostream>
#include <sstream>
#include "std_msgs/Float32.h"

float round(float count){
  float value = (int)(count * 100 + .5);
  return (float)value / 1000;
 }

int main(int argc, char **argv)
{
  using namespace std;
  ros::init(argc, argv, "mini_music");
  ros::NodeHandle n;
  ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1);
  ros::Rate loop_rate(10);
  float count = 0;
  while (ros::ok())
  {
    std_msgs::String msg;

    std::stringstream ss;
    ss << round(count);
    msg.data = ss.str();

    ROS_INFO("%s", msg.data.c_str());

    chatter_pub.publish(msg);

    ros::spinOnce();

    loop_rate.sleep();
    count = count + 1;
  }


  return 0;
}
