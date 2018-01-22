from ev3dev.ev3 import *
from time import sleep, time


class StateJoint:

    def __init__(self, __motor, __updateTime, stateMoving):
        self.__motor = __motor
        self.__updateTime = __updateTime
        self.__currentSpeed = 0
        self.__currentAngle = 0
        self.stateMoving= stateMoving

    def getCurrentAngle(self):
        return self.__currentAngle

    def getCurrentSpeed(self):
        return self.__currentSpeed

    def startStateMonitor(self):
        while True:
            sleep()