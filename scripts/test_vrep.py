#! /usr/bin/env python2
import vrep_ur5_ros.vrep_connection as vc

con = vc.VrepConnection()

print(con.GetObjectHandle("manipulation_object"))
