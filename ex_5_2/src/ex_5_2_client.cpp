#include "ros/ros.h"
#include "iri_wam_reproduce_trajectory/ExecTraj.h"
#include <ros/package.h>
// Import the service message used by the service /trajectory_by_name

int main(int argc, char **argv) {
  ros::init(argc, argv,"execute_trajectory_node"); // Initialise a ROS node with the name execute_trajectory_node
  ros::NodeHandle nh;

  // Create the connection to the service /execute_trajectory
  ros::service::waitForService("/execute_trajectory"); // wait for service to be running
  ros::ServiceClient exe_traj = nh.serviceClient<iri_wam_reproduce_trajectory::ExecTraj>("/execute_trajectory");
  iri_wam_reproduce_trajectory::ExecTraj trj; // Create an object of type TrajByName
  // This ros::package::getPath works in the same way as $(find name_of_package) in the launch files.
  trj.request.file = ros::package::getPath("iri_wam_reproduce_trajectory") + "/config/get_food.txt";

  if (exe_traj.call(trj)) // Send through the connection the name of the path file to be executed  
  {
    ROS_INFO("Service succeesfully called"); // Print the result given by the service called
  } else {
    ROS_ERROR("Failed to call service /execute_trajectory");
    return 1;
  }

  return 0;
}