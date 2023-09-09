#include "ros/init.h"
#include "ros/node_handle.h"
#include "ros/publisher.h"
#include "ros/rate.h"
#include "ros/subscriber.h"
#include <cstdio>
#include <geometry_msgs/Twist.h>
#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>

class Scan {

public:
  float r;
  float m;
  float l;
  void callback(const sensor_msgs::LaserScan::ConstPtr &msg);
};

void Scan::callback(const sensor_msgs::LaserScan::ConstPtr
                        &msg) // Define a function called 'callback' that //
                              // receives a // parameter named 'msg'
{
  m = msg->ranges[360];
  l = msg->ranges[719]; // Print the value 'data' inside the 'msg' parameter
  r = msg->ranges[0];   // Print the value 'data' inside the 'msg' parameter
}

int main(int argc, char **argv) {
  ros::init(argc, argv, "topics_quiz_node");
  ros::NodeHandle nh;
  ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("cmd_vel", 1000);
  ros::Rate lr(2);
  Scan scan;
  ros::Subscriber sub =
      nh.subscribe("kobuki/laser/scan", 1000, &Scan::callback, &scan);
  geometry_msgs::Twist v;
  v.linear.x = 0.2;
  v.angular.z = 0;
  pub.publish(v);
  while (ros::ok()) {
    if (scan.m < 1) {
      v.linear.x = 0.1;
      v.angular.z = 0.2;
      pub.publish(v);
      ros::spinOnce();
      lr.sleep();
      ROS_INFO("Middle<1");
    } else if (scan.l < 1) {
      v.linear.x = 0.1;
      v.angular.z = -0.2;
      pub.publish(v);
      ros::spinOnce();
      lr.sleep();
      ROS_INFO("Left<1");
    } else if (scan.r < 1) {
      v.linear.x = 0.1;
      v.angular.z = 0.2;
      pub.publish(v);
      ros::spinOnce();
      lr.sleep();
      ROS_INFO("Right<1");
    } else {
      v.linear.x = 0.2;
      v.angular.z = 0;
      pub.publish(v);
      ros::spinOnce();
      lr.sleep();
      ROS_INFO("Middle>1");
    }
  }
  return 0;
}