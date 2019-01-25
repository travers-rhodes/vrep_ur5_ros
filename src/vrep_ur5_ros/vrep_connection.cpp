#include "vrep_ur5_ros/vrep_connection.h"

void VrepConnection::Initialize(std::vector<std::string> vrep_joint_names)
{
  // simxInt simxStart(const simxChar* connectionAddress,simxInt connectionPort,simxUChar waitUntilConnected,simxUChar doNotReconnectOnceDisconnected,simxInt timeOutInMs,simxInt commThreadCycleInMs)
  clientId_ = simxStart("127.0.0.1", 19997, 1, 0, 5000, 5);
  if (clientId_ == -1)
  {
    throw(std::runtime_error("could not connect to simulation"));
  }

  std::cout << "Successfully connected with id " << clientId_ << "\n";

  for (int i = 0; i < vrep_joint_names.size(); i++)
  { 
    int joint_handle;
    simxGetObjectHandle(clientId_, vrep_joint_names[i].c_str(), &joint_handle, simx_opmode_blocking);
    joint_handles_.push_back(joint_handle);
  }
  
  for (int i = 0; i < vrep_joint_names.size(); i++)
  { 
    std::cout << "I have a joint handle " << joint_handles_[i] << "\n";
  }

  // Streaming operation request (subscription) (function returns immediately (non-blocking)):
  // Start streaming the current joint position of each joint (so we can use buffer calls later for speed
  for (int i = 0; i < vrep_joint_names.size(); i++)
  {
    float joint_position_;
    simxGetJointPosition(clientId_,joint_handles_[i],&joint_position_,simx_opmode_streaming);
  }
}

void VrepConnection::Close()
{
  if (clientId_ != -1)
  {
    simxFinish(clientId_);
  }
}

void VrepConnection::SetJointTargetPosition(int jointId, float value)
{
  int returnCode = simxSetJointTargetPosition(clientId_, joint_handles_[jointId], value, simx_opmode_oneshot);
  //std::cout << "Return code from setting joint " << jointId << " to value " << value << " was " << returnCode;
}

float VrepConnection::GetJointPosition(int jointId)
{
  float value = 0;
  simxGetJointPosition(clientId_, joint_handles_[jointId], &value, simx_opmode_buffer);
  //std::cout << "I have a joint position for joint " << jointId << " of " << value << "\n";
  return value;
}
