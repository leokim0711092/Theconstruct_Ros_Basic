#include <ex_4_5/Age.h>
#include <ros/ros.h>

int main(int argc, char **argv) {
  ros::init(argc, argv, "age_topic");
  ros::NodeHandle nh;
  ros::Publisher pub = nh.advertise<ex_4_5::Age>(
      "age_info",
      1000); // publish the topic name "age_info" with ex_4_5.Age msg
  ros::Rate lp(2);

  ex_4_5::Age ag;
  ag.years = 5;
  ag.months = 2;
  ag.days = 25;

  while (ros::ok()) {
    pub.publish(ag);
    ros::spinOnce();
    lp.sleep();
  }
  return 0;
}