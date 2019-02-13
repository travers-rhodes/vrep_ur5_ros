#include <controller_manager/controller_manager.h>
#include <ros/ros.h>

#include "vrep_ur5_ros/vrep_ur5_hardware_interface.h"

//https://slaterobots.com/blog/5abd8a1ed4442a651de5cb5b/how-to-implement-ros_control-on-a-custom-robot
int main(int argc, char** argv)
{
  ros::init(argc, argv, "ur5_hardware_interface");
  ros::NodeHandle nh;
  ros::AsyncSpinner spinner(1);
  spinner.start();

  VrepConnection vrep_connection;

  std::vector<std::string> vrep_joint_names = {"shoulder_pan_joint",
                                "shoulder_lift_joint",
                                "elbow_joint",
                                "wrist_1_joint",
                                "wrist_2_joint",
                                "wrist_3_joint",
                                "finger_l_joint",
                                "finger_r_joint"};

  vrep_connection.Initialize(vrep_joint_names);
  VrepUR5HardwareInterface robot(&vrep_connection);
  controller_manager::ControllerManager controller_manager(&robot, nh);

  int loop_hz = 100;
  ros::Duration update_freq = ros::Duration(1.0/loop_hz);
  ros::Time previous = ros::Time::now();
  ros::Time current = ros::Time::now();

  while (ros::Time::now().toSec() == 0)
  {
    std::cout << "waiting for clock to publish";
    update_freq.sleep();
  }

  while (ros::ok())
  {
    current = ros::Time::now();
    robot.read(current, current-previous);
    controller_manager.update(current, current-previous);
    robot.write(current, current-previous); 
    previous = current;
    update_freq.sleep();
  }
}


