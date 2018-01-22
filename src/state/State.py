from ev3dev.ev3 import *
from time import sleep, time
from math import pi
from threading import Thread, Lock
#TODO: New Thread


class StateJoint:
    def __init__(self, __motor, __updateTime, __lockJoint):
        self.__motor = __motor
        self.__updateTime = __updateTime
        self.__currentSpeed = 0
        self.__currentAngle = 0
        self.__lastAngle = 0
        self.moving = False
        self.__lockJoint = __lockJoint
        self.threadState = Thread(target=self.startStateMonitor)
        self.threadState.setDaemon(True)
        self.threadState.start()


    def getCurrentAngle(self):
        return self.__currentAngle

    def getCurrentSpeed(self):
        return self.__currentSpeed

    def startStateMonitor(self):
        while True:
            self.__lastAngle = self.__currentAngle
            self.__currentAngle = self.__motor.rotation
            self.__currentSpeed = (self.__currentAngle - self.__lastAngle)*pi/180
            if self.__currentSpeed > 0.01:
                self.moving = True
            sleep(self.__updateTime)

