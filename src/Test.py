from ev3dev.ev3 import *
from src.util.JointManager import *
from time import *


def main():
    while True:
        J1.controllerJoint.setDesiredSpeed(1.0)
        J1.controllerJoint.moveStart()
        J2.controllerJoint.setDesiredSpeed(1.0)
        J2.controllerJoint.moveStart()
        sleep(2)
        J1.controllerJoint.moveStop(True)
        J2.controllerJoint.moveStop(True)

if __name__ == '__main__':
     main()