#include "ros/ros.h"
#include "std_srvs/Empty.h" 

int main(int argc, char **argv)
{
  ros::init(argc, argv, "service_move_bb8_in_circle_client"); // Initialise a ROS node
  ros::NodeHandle nh;
  
  // Create the connection to the service /move_bb8_in_circle
  ros::ServiceClient move_bb8_in_circle_service_client = nh.serviceClient<std_srvs::Empty>("/move_bb8_in_circle");
  std_srvs::Empty srv; // Create an object of type Empty
  
  if (move_bb8_in_circle_service_client.call(srv)) 
  {
    ROS_INFO("Service successfully called. Moving BB8 in a circle.");
  }
  else
  {
    ROS_ERROR("Failed to call service /move_bb8_in_circle");
    return 1;
  }

  return 0;
}