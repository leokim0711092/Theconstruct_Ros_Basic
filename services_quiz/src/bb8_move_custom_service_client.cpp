#include "ros/ros.h"
#include "services_quiz/BB8CustomServiceMessage.h"

int main(int argc, char **argv) {
  ros::init(argc, argv,
            "service_move_bb8_in_circle_client"); // Initialise a ROS node
  ros::NodeHandle nh;

  // Create the connection to the service /move_bb8_in_circle
  ros::ServiceClient move_bb8_in_circle_service_client =
      nh.serviceClient<services_quiz::BB8CustomServiceMessage>( "/move_bb8_in_square_custom");
  services_quiz::BB8CustomServiceMessage srv; // Create an object of type Empty
  srv.request.repetitions = 2;
  srv.request.side = 1;
  if (move_bb8_in_circle_service_client.call(srv)) {
    ROS_INFO("1 sqm Service successfully called. Moving BB8 in a circle.");
  } else {
    ROS_ERROR("Failed to call service /move_bb8_in_circle_custom");
    return 1;
  }

  srv.request.repetitions = 1;
  srv.request.side = 2;
  if (move_bb8_in_circle_service_client.call(srv)) {
    ROS_INFO("2 sqm Service successfully called. Moving BB8 in a circle.");
  } else {
    ROS_ERROR("Failed to call service /move_bb8_in_circle_custom");
    return 1;
  }

  return 0;
}