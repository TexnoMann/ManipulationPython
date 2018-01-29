from ev3dev.ev3 import *
from src.state.State import *
from src.controll.Controller import *
from src.util.Joint import *
from time import *
from threading import Lock
from src.controll.Controller import *

# Created motor-objects for joints
motor0 = LargeMotor(OUTPUT_A)
motor1 = LargeMotor(OUTPUT_B)
motor2 = LargeMotor(OUTPUT_C)
motor = [motor0, motor1, motor2]

# Created locks for joints multithreading
jointLock0 = Lock()
jointLock1 = Lock()
jointLock2 = Lock()
lock = [jointLock0, jointLock1, jointLock2]

# DIMOOOON Initialization JoinController: PI-for Speed, PID-for Angle
controllerJoint0 = PIDSpeedController(3.63, 50.3, 0, 0.025, motor[0], lock[0])
controllerJoint1 = PIDSpeedController(3.63, 50.3, 0, 0.025, motor[1], lock[1])
controllerJoint2 = PIDSpeedController(3.63, 50.3, 0, 0.025, motor[2], lock[2])

# Created State Manager for koordinates
stateJoint = StateJoint(motor, 0.01, lock)

# Initialization Joint
J0 = Joint(controllerJoint0)
J1 = Joint(controllerJoint1)
J2 = Joint(controllerJoint2)
