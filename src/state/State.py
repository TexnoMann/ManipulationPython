from ev3dev.ev3 import *
from time import sleep, time
from math import pi
from threading import Thread, Lock
#New Thread


class StateJoint:
    def __init__(self, __motor, __updateTime, __jointLock):
        self.__jointLock = __jointLock
        self.__motor = __motor
        self.__updateTime = __updateTime
        self.__currentSpeed = [0, 0, 0]
        self.__currentAngle = [0, 0, 0]
        self.__lastAngle = [0, 0, 0]
        self.moving = [False, False, False]
        self.threadState = Thread(target=self.startStateMonitor)
        self.threadState.setDaemon(True)
        self.threadState.start()

    def getCurrentAngle(self, numberJoint):
        return self.__currentAngle[numberJoint]

    def getCurrentSpeed(self, numberJoint):
        return self.__currentSpeed[numberJoint]

    def startStateMonitor(self):
        while True:
            for i in range(0, len(self.__motor)):
                self.__lastAngle[i] = self.__currentAngle[i]
                self.__jointLock[i].acquire()
                self.__currentAngle[i] = self.__motor[i].position
                self.__jointLock[i].release()
                self.__currentSpeed[i] = (self.__currentAngle[i] - self.__lastAngle[i])*pi/180
                if self.__currentSpeed[i] > 0.02:
                    self.moving[i] = True
            sleep(self.__updateTime)

