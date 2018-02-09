from ev3dev.ev3 import *
from time import *
from math import pi
from math import copysign
from threading import Thread, Lock
from src.state.State import *


# New thread

class PIDSpeedController:

    def __init__(self, __P, __I, __D, __updateTime, __motor, __jointLock, __pCount):
        self.__jointLock = __jointLock
        self.stateJoint = StateJoint(__motor, __updateTime, __jointLock, __pCount)
        self.__pCount = __pCount
        self.__P = __P
        self.__I = __I
        self.__D = __D
        self.__updateTime = __updateTime
        self.__motor = __motor
        self.__p = 0
        self.__i = 0
        self.__startTime = time()
        self.__desiredSpeed = 0
        self.__desiredAngle = 0
        self.__firstAngleError = 0
        self.__secondAngleError = 0
        self.__currentSpeedError = 0
        self.__firstSpeedError = 0
        self.__u = 0
        self.__uA = 0
        self.__times = 0
        self.__positionError = 0.04
        self.power = False
        self.angleMode = False
        self._holding = False
        self.threadController = Thread(target=self.startPIDSpeedController)
        self.threadController.setDaemon(True)
        self.threadController.start()

    def setDesiredSpeed(self, desiredSpeed):
        self.__jointLock.acquire()
        self.__desiredSpeed = desiredSpeed
        self.__jointLock.release()

    def setDesiredAngle(self, desiredAngle):
        self.__jointLock.acquire()
        self.__desiredAngle = desiredAngle
        if desiredAngle < 0:
            self.__desiredSpeed = abs(self.__desiredSpeed)*-1
        self.__jointLock.release()

    def startPIDSpeedController(self):
        currenttime = 0
        while True:
            self.stateJoint.stateUpdate()
            if self.power:
                if(self.angleMode and (not self.__inPosition())) or (not self.angleMode):
                    lasttime = time()
                    self.__firstSpeedError = self.__currentSpeedError
                    self.__currentSpeedError = self.__desiredSpeed - self.stateJoint.getCurrentSpeed()
                    self.__p = self.__currentSpeedError * self.__P
                    self.__i += self.__currentSpeedError * self.__updateTime * self.__I
                    self.__u = (self.__p + self.__i)
                    if abs(self.__u) > 100:
                        self.__u = copysign(1, self.__u) * 100
                    self.__motor.run_direct(duty_cycle_sp=self.__u)
                    currenttime = time()
                    sleep(self.__updateTime - (currenttime - lasttime))
            else:
                # Holding Joint
                if self._holding:
                    self.__motor.stop(stop_action='hold')
                else :
                    self.__motor.stop(duty_cycle_sp='0')
                sleep(self.__updateTime)

    def moveForever(self):
        self.__jointLock.acquire()
        self.power = True
        self.angleMode = False
        self.__jointLock.release()

    def moveToAngle(self):
        self.__jointLock.acquire()
        self.power = True
        self.angleMode = True
        self.__jointLock.release()

    def stop(self, holding):
        self.__jointLock.acquire()
        self.power = False
        self._holding = holding
        self.__jointLock.release()
        self.__p = 0
        self.__i = 0
        self.__firstAngleError = 0
        self.__secondAngleError = 0
        self.__currentSpeedError = 0
        self.__firstSpeedError = 0
        self.__u = 0
        self.__uA = 0
        self.__times = 0


    # TODO: AngleController
    def getSignalAngleController(self):
        self.__firstAngleError = self.__secondAngleError
        self.__secondAngleError = self.__desiredAngle - self.__currentAngle
        return self.__uA

    def getMotor(self):
        return self.__motor

    def __inPosition(self):
        if abs(self.__desiredAngle-self.stateJoint.getCurrentAngle()) <= 0.02:
            self.power = False
            return True
        else:
            return False
