from ev3dev.ev3 import *

from src.controll.PIDSpeedLowController import PIDSpeedController
from src.controll.TrajectoryController import TrajectoryController
from src.state.State import *
from src.controll.PIDSpeedLowController import *
from src.controll.PIDTrajectoryController import *
from src.util.Joint import *
from time import *
from threading import Lock
from src.controll.PIDSpeedLowController import *
from src.util.Manipulator import *

# MOVE_P = 6
# MOVE_I = 0.04
# MOVE_D = 22

# Created motor-objects for joints
motor0 = LargeMotor(OUTPUT_A)
motor1 = LargeMotor(OUTPUT_B)
motor2 = LargeMotor(OUTPUT_C)


# Created locks for joints multithreading
jointLock0 = Lock()
jointLock1 = Lock()
jointLock2 = Lock()

state0 = StateJoint(motor0, 0.05, jointLock0, 5, 1)
state1 = StateJoint(motor1, 0.05, jointLock1, 5, 1)
state2 = StateJoint(motor2, 0.05, jointLock2, 3, -1)

# Initialization JoinController: PI-for Speed
controllerJoint0 = PIDSpeedController(3.63, 50.3, 0, 0.055, motor0, jointLock0, state0)
controllerJoint1 = PIDSpeedController(3.63, 50.3, 0, 0.055, motor1, jointLock1, state1)
controllerJoint2 = PIDSpeedController(3.63, 50.3, 0, 0.055, motor2, jointLock2, state2)

trajectoryController = TrajectoryController(10.9500, 62.0156, 0.9971, 4.8140, 62.0156, 0, motor0, motor1, motor2, 5, 5, 3, 0.07, [state0, state1, state2])


# Initialization Joint
J0 = Joint(controllerJoint0)
J1 = Joint(controllerJoint1)
J2 = Joint(controllerJoint2)
joints = [J0, J1, J2]

man = Manipulator(joints, trajectoryController)
#logger = Logger(man, 0.3)
sleep(1)
man.moveHome()
