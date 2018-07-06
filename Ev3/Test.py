from math import sin, pi
from threading import Lock

from ev3dev.ev3 import *
from time import *

from src.controll.TrajectoryController import *
from src.util.TrajectoryPlaning import *


def go():
    # Created motor-objects for joints
    motor0 = LargeMotor(OUTPUT_A)
    motor0.reset()
    motor1 = LargeMotor(OUTPUT_B)
    motor1.reset()
    motor2 = LargeMotor(OUTPUT_C)
    motor2.reset()

    controllerJoint = TrajectoryController(9.2, 49.0, 0.99, 11.5, 115.0, 0, motor0, motor1, motor2, 5, 5, 3, 0.05)
    print("go")
    sleep(5)
    trj = TrajectoryPlaning("trajectory/test.out")
    way = trj.readTrajectory()

    controllerJoint.moveOnTrajectory(way)
    controllerJoint.waitFinishMoving()
    sleep(10)


def main():
    go()


if __name__ == "__main__":
    main()