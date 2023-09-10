#include "ros/ros.h"
#include "std_srvs/Empty.h"
#include "geometry_msgs/Twist.h"

ros::Publisher vel_pub;
geometry_msgs::Twist vel_msg;

bool my_callback(std_srvs::Empty::Request  &req,
                 std_srvs::Empty::Response &res)
{  
  ROS_INFO("The Service move_bb8_in_circle has been called");
  vel_msg.linear.x = 0.2;
  vel_msg.angular.z = 0.2;
  vel_pub.publish(vel_msg);     
  ROS_INFO("Finished service move_bb8_in_circle  ");
  return true;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "service_move_bb8_in_circle_server");
  ros::NodeHandle nh;

  ros::ServiceServer my_service = nh.advertiseService("/move_bb8_in_circle", my_callback);
  vel_pub = nh.advertise<geometry_msgs::Twist>("cmd_vel", 1000);
  ROS_INFO("Service /move_bb8_in_circle_custom Ready");
  ros::spin();

  return 0;
}