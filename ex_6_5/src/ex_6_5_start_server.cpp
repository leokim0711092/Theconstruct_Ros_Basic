#include "geometry_msgs/Twist.h"
#include "my_custom_srv_msg_pkg/MyCustomServiceMessage.h"
#include "ros/ros.h"

ros::Publisher vel_pub;
geometry_msgs::Twist vel_msg;

bool my_callback(my_custom_srv_msg_pkg::MyCustomServiceMessage::Request &req,
                 my_custom_srv_msg_pkg::MyCustomServiceMessage::Response &res) {
  ROS_INFO("The Service move_bb8_in_circle_custom has been called");
  vel_msg.linear.x = 0.2;
  vel_msg.angular.z = 0.2;
  int i = 0;
  while (i < req.duration) {
    vel_pub.publish(vel_msg);
    usleep(1000000); // We set 1000000 because the time is set in microseconds
    i++;
  }
  vel_msg.linear.x = 0;
  vel_msg.angular.z = 0;
  vel_pub.publish(vel_msg);
  res.success = true;
  ROS_INFO("Finished service move_bb8_in_circle  ");
  return true;
}

int main(int argc, char **argv) {
  ros::init(argc, argv, "service_move_bb8_in_circle_server");
  ros::NodeHandle nh;

  ros::ServiceServer my_service =
      nh.advertiseService("/move_bb8_in_circle_custom", my_callback);
  vel_pub = nh.advertise<geometry_msgs::Twist>("cmd_vel", 1000);
  ROS_INFO("Service /move_bb8_in_circle_custom Ready");
  ros::spin();

  return 0;
}