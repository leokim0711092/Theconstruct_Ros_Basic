#include <ros/ros.h>

int main(int argc, char **argv) {

  ros::init(argc, argv, "ObiWan");
  ros::NodeHandle nh;
  ros::Rate loop_rate(2); // We create a Rate object of 2Hz

  while (ros::ok()) // Endless loop until Ctrl + C
  {
    ROS_INFO("Help me Obi-Wan Kenobi, you're my only hope");
    ros::spinOnce();
    loop_rate
        .sleep(); // We sleep the needed time to maintain the Rate fixed above
  }

  return 0;
}

// This program creates an endless loop that repeats itself 2 times per second
// (2Hz) until somebody presses Ctrl + C in the Shell