from ev3dev.ev3 import *
from src.state.State import *
from src.controll.Controller import *
from src.util.Joint import *
from time import *
from threading import Lock
from src.controll.Controller import *

motor1 = LargeMotor(OUTPUT_A)
motor2 = LargeMotor(OUTPUT_B)
jointLock1 = Lock()
jointLock2 = Lock()

controllerJoint1 = PIDSpeedController(3.63, 50.3, 0, 0.050, motor1, jointLock1)
controllerJoint2 = PIDSpeedController(3.63, 50.3, 0, 0.050, motor2, jointLock2)


stateJoint1 = StateJoint(motor1, 0.015, jointLock1)
stateJoint2 = StateJoint(motor2, 0.015, jointLock2)


J1 = Joint(controllerJoint1, stateJoint1)
J2 = Joint(controllerJoint2, stateJoint2)

