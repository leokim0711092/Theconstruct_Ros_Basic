#include "geometry_msgs/Twist.h"
#include "ros/init.h"
#include "ros/ros.h"
#include "services_quiz/BB8CustomServiceMessage.h"

ros::Publisher vel_pub;
geometry_msgs::Twist vel_msg;

bool my_callback(services_quiz::BB8CustomServiceMessage::Request &req,
                 services_quiz::BB8CustomServiceMessage::Response &res) {
  ROS_INFO("The Service move_bb8_in_circle_custom has been called");
  vel_msg.linear.x = 0;
  vel_msg.linear.y = 0;
  float t = req.side;
  for (int i = 0; i < req.repetitions; i++) {
    for (int j = 0;j<4;j++){
        vel_msg.linear.x = 0.2;
        vel_msg.angular.z = 0;
        vel_pub.publish(vel_msg);
        usleep(4500000 *t);

        vel_msg.angular.z = 0.2;
        vel_msg.linear.x = 0;
        vel_pub.publish(vel_msg);
        usleep(8000000); 

    }
    }

  vel_msg.linear.x = 0;
  vel_msg.angular.z = 0;
  vel_pub.publish(vel_msg);
  res.success = true;
  ROS_INFO("Finished service move_bb8_in_circle  ");
  return res.success;
}

int main(int argc, char **argv) {
  ros::init(argc, argv, "service_move_bb8_in_circle_server");
  ros::NodeHandle nh;

  ros::ServiceServer my_service =
      nh.advertiseService("/move_bb8_in_square_custom", my_callback);
  vel_pub = nh.advertise<geometry_msgs::Twist>("cmd_vel", 1000);
  ROS_INFO("Service /move_bb8_in_square_custom Ready");
  ros::spin();
  return 0;
}