from ev3dev.ev3 import *
from time import sleep, time
from math import pi
from threading import Thread, Lock
from src.state.Logger import *


class StateJoint:
    def __init__(self, __motor, __updateTime, __pCount, __inverted):
        self.__calibCoord = 0
        self.inverted = __inverted
        self.__pCount = __pCount
        self.jointLock = Lock()
        self.__motor = __motor
        self.__updateTime = __updateTime
        self.__currentSpeed = 0
        self.__lastSpeed = 0
        self.__currentAngle = 0
        self.__lastAngle = 0
        self.__moving = False
        self.__stalled = True

    def getCurrentAngle(self):
        return self.__currentAngle

    def getCurrentSpeed(self):
        return self.__currentSpeed

    def getLastAngle(self):
        return self.__lastAngle

    def getLastSpeed(self):
        return self.__lastSpeed

    def stateUpdate(self):
        self.__lastAngle = self.__currentAngle
        self.__lastSpeed = self.__currentSpeed
        self.__jointLock.acquire()
        self.__currentAngle = round((self.__motor.position*pi/180.0/self.__pCount*self.inverted+self.__calibCoord), 5)
        self.__currentSpeed = round(((self.__currentAngle - self.__lastAngle)/self.__updateTime), 5)
        self.__jointLock.release()
        if abs(self.__currentSpeed) <= 0.007:
            self.__jointLock.acquire()
            self.__stalled = True
            self.__jointLock.release()
        else:
            self.__jointLock.acquire()
            self.__stalled = False
            self.__jointLock.release()

    def isStalled(self):
        return self.__stalled

    def resetState(self):
        self.__currentAngle = 0
        self.__currentSpeed = 0

    def setCalibCoord(self, coord):
        self.__calibCoord = coord

    def removeSpeed(self):
        self.__currentSpeed = 0
        self.__lastAngle = self.__currentAngle


