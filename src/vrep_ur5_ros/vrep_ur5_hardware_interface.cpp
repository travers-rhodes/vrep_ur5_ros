#include "vrep_ur5_ros/vrep_ur5_hardware_interface.h"

VrepUR5HardwareInterface::VrepUR5HardwareInterface(VrepConnection *vrep_interface)
{
   std::vector<std::string> joint_names = {"shoulder_pan_joint",
                                "shoulder_lift_joint",
                                "elbow_joint",
                                "wrist_1_joint",
                                "wrist_2_joint",
                                "wrist_3_joint",
                                "finger_l_joint",
                                "finger_r_joint"};
   
   // connect and register the joint state interfaces
   for (int i = 0; i < NUMBER_OF_JOINTS; i++)
   {
     hardware_interface::JointStateHandle state_handle(joint_names[i], &pos_[i], &vel_[i], &eff_[i]);
     jnt_state_interface_.registerHandle(state_handle);
   }

   registerInterface(&jnt_state_interface_);

   // connect and register the joint position interfaces
   for (int i = 0; i < NUMBER_OF_JOINTS; i++)
   {
     hardware_interface::JointHandle pos_handle(jnt_state_interface_.getHandle(joint_names[i]), &cmd_[i]);
     jnt_pos_interface_.registerHandle(pos_handle);
   }

   registerInterface(&jnt_pos_interface_);
   vrep_interface_ = vrep_interface;
}

void VrepUR5HardwareInterface::write(const ros::Time& time, const ros::Duration& period)
{
  for (int i = 0; i < NUMBER_OF_JOINTS; i++)
  {
    vrep_interface_->SetJointTargetPosition(i, cmd_[i]);
  }
}

void VrepUR5HardwareInterface::read(const ros::Time& time, const ros::Duration& period)
{
  // for now, ignore the vel_, eff_ params
  for (int i = 0; i < NUMBER_OF_JOINTS; i++)
  {
    pos_[i] = vrep_interface_->GetJointPosition(i);
  }
}
