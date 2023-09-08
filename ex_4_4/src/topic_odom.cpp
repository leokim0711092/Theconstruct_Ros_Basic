#include <ros/ros.h>
#include <nav_msgs/Odometry.h>

void counterCallback(const nav_msgs::Odometry::ConstPtr& msg) // Define a function called 'callback' that receives a                                                                // parameter named 'msg' 
{
  ROS_INFO("%s", msg->header.frame_id.c_str()); // Print the value 'header' inside the 'msg' parameter
  ROS_INFO("%f", msg->pose.pose.position.x); // Print the value 'data' inside the 'msg' parameter
  ROS_INFO("%f", msg->twist.twist.linear.x); // Print the value 'data' inside the 'msg' parameter
}

int main(int argc, char** argv) {

    ros::init(argc, argv, "odom_subscriber"); // Initiate a Node called 'topic_subscriber'
    ros::NodeHandle nh;
    
    ros::Subscriber sub = nh.subscribe("odom", 1000, counterCallback); // Create a Subscriber object that will                                                                               // listen to the /counter topic and will
                                                                          // call the 'callback' function each time                                                                             // it reads something from the topic
    
    ros::spin(); // Create a loop that will keep the program in execution
    
    return 0;
}