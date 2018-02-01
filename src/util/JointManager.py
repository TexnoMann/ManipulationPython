from ev3dev.ev3 import *
from src.state.State import *
from src.controll.Controller import *
from src.util.Joint import *
from time import *
from threading import Lock
from src.controll.Controller import *
from src.numKinematic.PZK import *

#Configuration manipulator
InstrL = 0
a = [0.055, 0.15, 0.14+InstrL]
d = [0.16, 0.0, 0.0]

# Created motor-objects for joints
motor0 = LargeMotor(OUTPUT_A)
motor1 = LargeMotor(OUTPUT_B)
motor2 = LargeMotor(OUTPUT_C)


# Created locks for joints multithreading
jointLock0 = Lock()
jointLock1 = Lock()
jointLock2 = Lock()


# DIMOOOON Initialization JoinController: PI-for Speed, PID-for Angle
controllerJoint0 = PIDSpeedController(3.63, 50.3, 0, 0.045, motor0, jointLock0, 5)
controllerJoint1 = PIDSpeedController(3.63, 50.3, 0, 0.045, motor1, jointLock1, 5)
controllerJoint2 = PIDSpeedController(3.63, 50.3, 0, 0.045, motor2, jointLock2, 3)

# Initialization Joint
J0 = Joint(controllerJoint0, 0, 1)
J1 = Joint(controllerJoint1, 2.95, 1)
J2 = Joint(controllerJoint2, 2.79, 1)

fKinematics = ForwardKinematic(a, d)
