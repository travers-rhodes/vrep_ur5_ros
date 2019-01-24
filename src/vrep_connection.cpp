#include "vrep_ur5_ros/vrep_connection.h"

VrepConnection::Initialize()
{
  // simxInt simxStart(const simxChar* connectionAddress,simxInt connectionPort,simxUChar waitUntilConnected,simxUChar doNotReconnectOnceDisconnected,simxInt timeOutInMs,simxInt commThreadCycleInMs)
  clientId_ = simxStart("localhost", 19997, 1, 0, 5000, 5);
  if (clientId == -1)
  {
    throw(std::runtime_error("could not connect to simulation"));
  }
}

VrepConnection::Close()
{
  if (clientId_ != -1)
  {
    simxFinish(clientId_);
  }
}
