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

#Create stateHandlers from joints
state0 = StateJoint(motor0, 0.06, 7, -1)
state1 = StateJoint(motor1, 0.06, 2.25, 1)
state2 = StateJoint(motor2, 0.06, 2.25, -1)

# Initialization JoinController: PI-for Speed
controllerJoint0 = PIDSpeedController(3.63, 50.3, 0, 0.06, motor0, state0, touchHardResetSensor)
controllerJoint1 = PIDSpeedController(3.63, 50.3, 0, 0.06, motor1, state1, touchHardResetSensor)
controllerJoint2 = PIDSpeedController(3.63, 50.3, 0, 0.06, motor2, state2, touchHardResetSensor)
#trajectoryController = TrajectoryController(10.9500, 62.0156, 0.9971, 4.8140, 62.0156, 0, motor0, motor1, motor2, 0.06, [state0, state1, state2], touchHardResetSensor)

trajectoryController = TrajectoryController(14.3197, 93.9408, 0.9971, 5.0798, 93.9408, 0, motor0, motor1, motor2, 0.06, [state0, state1, state2], touchHardResetSensor)


# Initialization Joint
J0 = Joint(controllerJoint0)
J1 = Joint(controllerJoint1)
J2 = Joint(controllerJoint2)
joints = [J0, J1, J2]

calibration = Calibration(joints, [-1, 1, -1], [1.4223, 2.05, 2.7945])
DHparam = DHParameters([0.0125, 0.165, 0.22], [0.17, 0.0, 0.0], [0.17, 0.0, 0.0], 0)

man = Manipulator(joints, trajectoryController, DHparam, calibration)
#logger = Logger(man, 0.3)
sleep(1)
