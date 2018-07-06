from math import *
from threading import Lock, Thread

from ev3dev.ev3 import *
from time import *

from src.state.State import *


class TrajectoryController:
    def __init__(self, __P, __I, __D,__PA, __IA, __DA, __motor1, __motor2, __motor3, __updateTime, __stateList, __hardResetTouch):

        self.__hardResetTouch = __hardResetTouch
        self.__antiWindUpValue = 30
        self.__updateTime = __updateTime
        self.__controllerOn = False
        self.__way = ()
        self.__motor = (__motor1, __motor2, __motor3)
        self.__P = __P
        self.__I = __I
        self.__D = __D
        self.__PA = __PA
        self.__IA = __IA
        self.__DA = __DA
        self.__manipulatorLock = Lock()
        self.stateMan = __stateList

        self.__positionError = 0.002
        self.__power = False
        self.__holding = False

        self.__lastSpeedError = [0.0, 0.0, 0.0]

        self.__lastAngleError = [0.0, 0.0, 0.0]
        self.__currentSpeedError = [0.0, 0.0, 0.0]
        self.__currentAngleError = [0.0, 0.0, 0.0]
        self.__desiredSpeed = [0.0, 0.0, 0.0]
        self.__desiredAngle = [0.0, 0.0, 0.0]

        sleep(2)
        self.threadController = Thread(target=self.startTrjController)
        self.threadController.setDaemon(True)
        self.threadController.start()

    def startThread(self):
        self.__controllerOn = True
        self.threadController.__init__(target=self.startTrjController)
        self.threadController.setDaemon(True)
        self.threadController.start()


    def startTrjController(self):

        while True:
            if self.__controllerOn:
                if self.__power:
                    pA, iA, dA, uA, pS, iS, dS, uS = ([0.0, 0.0, 0.0] for i in range(8))
                    for pointNumber in range(len(self.__way)):
                        lasttime = time()
                        for s in self.stateMan:
                            s.stateUpdate()
                        for i in range(len(self.stateMan)):
                            self.__desiredAngle[i] = round(self.__way[pointNumber][0][i], 3)
                            self.__desiredSpeed[i] = round(self.__way[pointNumber][1][i], 3)

                            self.__lastAngleError[i] = self.__currentAngleError[i]
                            self.__lastSpeedError[i] = self.__currentSpeedError[i]
                            self.__currentAngleError[i] = self.__desiredAngle[i] - self.stateMan[i].getCurrentAngle()

                            pA[i] = self.__currentAngleError[i]*self.__PA
                            iA[i] = self.__currentAngleError[i]*self.__updateTime*self.__updateTime*self.__IA
                            dA[i] = (self.__currentAngleError[i] - self.__lastAngleError[i])/self.__updateTime*self.__DA
                            uA[i] = pA[i] + iA[i] + dA[i]

                            self.__currentSpeedError[i] = self.__desiredSpeed[i] + uA[i] - self.stateMan[i].getCurrentSpeed()

                            pS[i] = self.__currentSpeedError[i]*self.__P
                            iS[i] = self.__currentSpeedError[i]*self.__updateTime*self.__I
                            if abs(iS[i]) > self.__antiWindUpValue:
                                iS[i] = copysign(1, iS[i])*self.__antiWindUpValue
                            dS[i] = (self.__currentSpeedError[i] - self.__lastSpeedError[i])/self.__updateTime*self.__D
                            uS[i] = pS[i] + iS[i] + dS[i]
                            if abs(uS[i]) > 100:
                                uS[i] = copysign(1, uS[i]) * 100

                        for m in range(len(self.__motor)):
                            self.__motor[m].run_direct(duty_cycle_sp=uS[m]*self.stateMan[m].inverted)

                        currenttime = time()
                        sleep(self.__updateTime - (currenttime - lasttime))
                    self.stop(True)

                else:
                    self.__stopping()
            else: break
        self.__controllerOn = False

    def moveOnTrajectory(self, way):
        self.startThread()
        self.__manipulatorLock.acquire()
        self.__way = way
        print("start moving")
        self.__power = True
        self.__manipulatorLock.release()

    def stop(self, holding):
        self.__manipulatorLock.acquire()
        self.__power = False
        self.__holding = holding
        self.__stopping()
        self.__manipulatorLock.release()
        sleep(0.5)
        self.__manipulatorLock.acquire()
        self.__controllerOn = False
        self.__manipulatorLock.release()

    def waitFinishMoving(self):
        while True:
            sleep(self.__updateTime*10)
            if not self.__controllerOn:
                break
    def getMotors(self):
        return self.__motor

    def __stopping(self):
        self.__currentSpeedError = [0.0, 0.0, 0.0]
        self.__desiredSpeed = [0.0, 0.0, 0.0]
        for s in self.stateMan:
            s.removeSpeed()

            # Holding Joint
        if self.__holding:
            for m in self.__motor:
                m.stop(stop_action='hold')
        else:
            for m in self.__motor:
                m.stop(duty_cycle_sp='0')
        sleep(self.__updateTime)
