#!/usr/bin/env python2
import vrep

class VrepConnection(object):
  def __init__(self):
    self.clientId = vrep.simxStart("127.0.0.1", 19992, 1, 0, -10000, 5)
    if (self.clientId == -1):
      raise(RuntimeError("could not connect to simulation"))

  def LoadModel(self, modelPathAndName):
    return vrep.simxLoadModel(self.clientId, modelPathAndName, 0, vrep.simx_opmode_blocking);
  
  def GetObjectHandle(self, objectName):
    return vrep.simxGetObjectHandle(self.clientId, objectName, vrep.simx_opmode_blocking);
  
  def SetObjectPosition(self, objectHandle, position):
    # set position relative to global frame
    vrep.simxSetObjectPosition(self.clientId, objectHandle, -1, position, vrep.simx_opmode_oneshot);
 
  # quaternion is (x,y,z,w) 
  def SetObjectQuaternion(self, objectHandle, quaternion):
    # set position relative to global frame
    vrep.simxSetObjectQuaternion(self.clientId, objectHandle, -1, quaternion, vrep.simx_opmode_oneshot);

  # get position relative to global frame
  def GetObjectPosition(self, objectHandle):
    return vrep.simxGetObjectPosition(self.clientId, objectHandle, -1, vrep.simx_opmode_blocking);
  
