from ev3dev.ev3 import *
from src.state.State import *
from src.controll.Controller import *
from src.util.Joint import *
from time import *
from threading import Lock
from src.controll.Controller import *

motor1 = LargeMotor(OUTPUT_A)
motor2 = LargeMotor(OUTPUT_B)
motor3 = LargeMotor(OUTPUT_C)
jointLock1 = Lock()
jointLock2 = Lock()
jointLock3 = Lock()

controllerJoint1 = PIDSpeedController(3.63, 50.3, 0, 0.030, motor1, jointLock1)
controllerJoint2 = PIDSpeedController(3.63, 50.3, 0, 0.030, motor2, jointLock2)
controllerJoint3 = PIDSpeedController(3.63, 50.3, 0, 0.030, motor3, jointLock3)


stateJoint3 = StateJoint(motor3, 0.1, jointLock3)

J1 = Joint(controllerJoint1)
J2 = Joint(controllerJoint2)
J3 = Joint(controllerJoint3)

