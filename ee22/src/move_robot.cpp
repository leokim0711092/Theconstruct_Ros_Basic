#include "ros/init.h"
#include "ros/node_handle.h"
#include "ros/publisher.h"
#include "ros/rate.h"
#include <geometry_msgs/Twist.h>
#include <ros/ros.h>

int main(int argc, char **argv) {

  ros::init(argc, argv, "move_robot");
  ros::NodeHandle nh;
  ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("cmd_vel", 1000);
  ros::Rate lr(2);
  geometry_msgs::Twist vl;
  vl.linear.x = 0.5;
  vl.angular.z = 0.2;

  while (ros::ok()) {
    pub.publish(vl);
    ros::spinOnce();
    lr.sleep();
  }
  return 0;
}