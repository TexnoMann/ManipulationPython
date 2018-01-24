from ev3dev.ev3 import *
from src.state.State import *
from src.controll.Controller import *
from src.util.Joint import *
from time import *
from threading import *
from src.controll.PIDControll import *

motor1 = LargeMotor(OUTPUT_A)
motor2 = LargeMotor(OUTPUT_B)
motor3 = LargeMotor(OUTPUT_C)

controllerJoint1 = ControllerJoint(3, 50, 0, 0.015, motor1)
controllerJoint2 = ControllerJoint(3, 50, 0, 0.015, motor2)
controllerJoint3 = ControllerJoint(3, 50, 0, 0.015, motor3)

stateJoint1 = StateJoint(motor1, 0.015)
stateJoint2 = StateJoint(motor2, 0.015)
stateJoint3 = StateJoint(motor3, 0.015)

J1 = Joint(controllerJoint1, stateJoint1)
J2 = Joint(controllerJoint2, stateJoint2)
J3 = Joint(controllerJoint3, stateJoint3)
