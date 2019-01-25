#include "CopellaRobotics/remoteApi/extApi.h"
#include "CopellaRobotics/include/v_repConst.h"
#include <iostream>
#include <stdexcept>
#include <vector>

class VrepConnection
{
  private:
    int clientId_ = -1;
    std::vector<int> joint_handles_;
  public:
    void Initialize(std::vector<std::string> vrep_joint_names);
    void Close();
    void SetJointTargetPosition(int jointId, float value);
    float GetJointPosition(int jointId);
};
