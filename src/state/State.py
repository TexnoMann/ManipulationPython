from ev3dev.ev3 import *
from time import sleep, time
from math import pi
from threading import Thread, Lock
#New Thread


class StateJoint:
    def __init__(self, __motor, __updateTime, __jointLock, __pCount):
        self.__pCount = __pCount
        self.__jointLock = __jointLock
        self.__motor = __motor
        self.__updateTime = __updateTime
        self.__currentSpeed = 0
        self.__currentAngle = 0
        self.__lastAngle = 0
        self.__moving = False

        self.__stalled = True


    def getCurrentAngle(self):
        return self.__currentAngle

    def getCurrentSpeed(self):
        return self.__currentSpeed

    def stateUpdate(self):
        self.__lastAngle = self.__currentAngle
        self.__jointLock.acquire()
        self.__currentAngle = self.__motor.position*pi/180/self.__pCount
        self.__currentSpeed = (self.__currentAngle - self.__lastAngle)/self.__updateTime
        self.__jointLock.release()

        if abs(self.__currentSpeed) <= 0.03:
            self.__jointLock.acquire()
            self.__stalled = True
            self.__jointLock.release()
        else:
            self.__jointLock.acquire()
            self.__stalled = False
            self.__jointLock.release()

    def isStalled(self):
        return self.__stalled


