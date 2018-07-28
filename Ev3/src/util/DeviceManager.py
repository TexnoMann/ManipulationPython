from ev3dev.ev3 import *

from src.controll.PIDSpeedLowController import PIDSpeedController
from src.controll.TrajectoryController import TrajectoryController
from src.numKinematic.DHParameters import DHParameters
from src.state.State import *
from src.controll.PIDSpeedLowController import *

from src.util.Joint import *
from time import *
from threading import Lock
from src.util.Manipulator import *

# MOVE_P = 6
# MOVE_I = 0.04
# MOVE_D = 22
touchHardResetSensor = TouchSensor("in1")

# Created motor-objects from joints
motor0 = LargeMotor(OUTPUT_A)
motor1 = LargeMotor(OUTPUT_B)
motor2 = LargeMotor(OUTPUT_C)

#Create stateHandlers for joints
state0 = StateJoint(motor0, 0.06, 7, -1)
state1 = StateJoint(motor1, 0.06, 5.5, 1)
state2 = StateJoint(motor2, 0.06, 5.5, -1)

# Initialization JoinController: PID-Controller for Speed
controllerJoint0 = PIDSpeedController(17.5, 81, 0.9, 0.06, motor0, state0, touchHardResetSensor)
controllerJoint1 = PIDSpeedController(17.5, 81, 0.9, 0.06, motor1, state1, touchHardResetSensor)
controllerJoint2 = PIDSpeedController(17.5, 81, 0.9, 0.06, motor2, state2, touchHardResetSensor)
#trajectoryController = TrajectoryController(10.9500, 62.0156, 0.9971, 4.8140, 62.0156, 0, motor0, motor1, motor2, 0.06, [state0, state1, state2], touchHardResetSensor)

trajectoryController = TrajectoryController(15.1, 81, 0.97, 20, 35, 0.1, motor0, motor1, motor2, 0.06, [state0, state1, state2], touchHardResetSensor)


# Initialization Joint
J0 = Joint(controllerJoint0)
J1 = Joint(controllerJoint1)
J2 = Joint(controllerJoint2)
joints = [J0, J1, J2]

calibration = Calibration(joints, [-1, 1, -1], [1.55, 1.80, 2.8])
DHparam = DHParameters([0.06, 0.15, 0.145], [0.163, 0.0, 0.0], [0, 0.0, 0.0], 0.07)

man = Manipulator(joints, trajectoryController, DHparam, calibration)
#logger = Logger(man, 0.3)
sleep(1)
