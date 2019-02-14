#!/usr/bin/env python2
import vrep

class VrepConnection(object):
  def __init__(self):
    self.clientId = vrep.simxStart("127.0.0.1", 19997, 1, 0, 5000, 5)
    if (self.clientId == -1):
      raise(RuntimeError("could not connect to simulation"))

  def LoadModel(modelPathAndName):
    vrep.simxLoadModel(clientId_, modelPathAndName.c_str(), 0, NULL, vrep.simx_opmode_blocking);
  
  def GetObjectHandle(objectName):
    (returnCode, objectHandle) = vrep.simxGetObjectHandle(clientId_, objectName, vrep.simx_opmode_blocking);
    return objectHandle;
  
  def SetObjectPosition(objectHandle, position):
    # set position relative to global frame
    vrep.simxSetObjectPosition(clientId_, objectHandle, -1, position, vrep.simx_opmode_oneshot);

