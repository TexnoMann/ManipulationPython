from ev3dev.ev3 import *
import src.util.Joint as util
import src.controll.Controller as controll
import src.state.State as state

cJoint1 = controll.ControllerJoint(OUTPUT_A, 15)
sJoint1 = state.StateJoint(OUTPUT_A, 10)
joint1 = util.Joint(cJoint1, sJoint1)
joint1.controllerJoint.getDesiredAngle()
