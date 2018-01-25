from ev3dev.ev3 import *
from time import *
from math import pi
from math import copysign
from threading import Thread, Lock

#New thread

class PIDSpeedController:

    def __init__(self, __P, __I, __D, __updateTime, __motor):
        self.__P = __P
        self.__I = __I
        self.__D = __D
        self.__updateTime = __updateTime
        self.__motor = __motor
        self.__p = 0
        self.__i = 0
        self.__startTime = time()
        self.__desiredSpeed = 0
        self.__currentSpeed = 0
        self.__currentAngle = 0
        self.__firstAngle = 0
        self.__firstSpeed = 0
        self.__firstAngleError = 0
        self.__secondAngleError = 0
        self.__currentSpeedError = 0
        self.__firstSpeedError = 0
        self.__u = 0
        self.__uA = 0
        self.__times = 0
        self.power = False
        self._holding = False
        self.threadController = Thread(target=self.startPIDSpeedController)
        self.threadController.setDaemon(True)
        self.threadController.start()

    def setDesiredSpeed(self, desiredSpeed):
        self.__desiredSpeed = desiredSpeed

    def setCurrentAngle(self, currentAngle):
            self.__currentAngle = currentAngle


    def startPIDSpeedController(self):
        while True:
            if self.power:
                #Holding Joint
                if self._holding:
                    self.__motor.stop(stop_action='hold')
                else:
                    self.__firstAngle = self.__currentAngle
                    self.__firstSpeed = self.__currentSpeed
                    self.__currentSpeed = (self.__currentAngle-self.__firstAngle)/self.__updateTime
                    self.__firstSpeedError = self.__currentSpeedError
                    self.__currentSpeedError = self.__desiredSpeed-self.__currentSpeed

                    self.__p = self.__currentSpeedError*self.__P
                    self.__i += self.__currentSpeedError*self.__updateTime*self.__I
                    self.__u = (self.__p+self.__i)
                    if abs(self.__u) > 100:
                        self.__u = copysign(1, self.__u)*100
                    self.__motor.run_direct(duty_cycle_sp=self.__u)
                    sleep(self.__updateTime)

    def move(self):
        self.power = True

    def stop(self, holding):
        self.power = False
        self._holding = holding

    def getSignalAngleController(self):
        self.__firstAngleError = self.__secondAngleError
        self.__secondAngleError = self.__desiredAngle-self.__currentAngle
        return self.__uA

