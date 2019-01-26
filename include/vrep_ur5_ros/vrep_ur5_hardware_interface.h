#include <hardware_interface/joint_command_interface.h>
#include <hardware_interface/joint_state_interface.h>
#include <hardware_interface/robot_hw.h>
#include "vrep_ur5_ros/vrep_connection.h"

#define NUMBER_OF_JOINTS 8

class VrepUR5HardwareInterface : public hardware_interface::RobotHW
{
  public:
    VrepUR5HardwareInterface();
    void write(const ros::Time& time, const ros::Duration& period);
    void read(const ros::Time& time, const ros::Duration& period);
  private:
    VrepConnection vrep_interface_; 
    hardware_interface::JointStateInterface jnt_state_interface_;
    hardware_interface::PositionJointInterface jnt_pos_interface_;
    double cmd_[NUMBER_OF_JOINTS];
    double pos_[NUMBER_OF_JOINTS];
    double vel_[NUMBER_OF_JOINTS];
    double eff_[NUMBER_OF_JOINTS];
};
