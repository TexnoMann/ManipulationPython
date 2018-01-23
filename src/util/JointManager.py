from ev3dev.ev3 import *
from src.state.State import *
from src.controll.Controller import *
from src.util.Joint import *
from time import *
from threading import *
from src.controll.PIDControll import *


controllerJoint1 = ControllerJoint(3, 50, 0, 0.015, OUTPUT_A)
controllerJoint2 = ControllerJoint(3, 50, 0, 0.015, OUTPUT_B)
controllerJoint3 = ControllerJoint(3, 50, 0, 0.015, OUTPUT_C)

stateJoint1 = StateJoint(OUTPUT_A, 0.015)
stateJoint2 = StateJoint(OUTPUT_B, 0.015)
stateJoint3 = StateJoint(OUTPUT_C, 0.015)

J1 = Joint(controllerJoint1, stateJoint1)
J2 = Joint(controllerJoint2, stateJoint2)
J3 = Joint(controllerJoint3, stateJoint3)
