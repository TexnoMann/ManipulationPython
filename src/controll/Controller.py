from ev3dev.ev3 import *
import src.controll.PIDControll


class ControllerJoint:

    def __init__(self, __motor, __updateTime, power):
        self.__motorPort = __motor
        self.__updateTime = __updateTime
        #self.__controller = __controller
        self.__desiredSpeed = 0
        self.__desiredAngle = 0
        self.power = 0

    def move(self, strt):
        print(strt)

    def setSpeed(self, desiredSpeed):
        self.__desiredSpeed = desiredSpeed

    def setAngle(self, desiredAngle):
        self.__desiredAngle= desiredAngle

    def getDesiredSpeed(self):
        return self.__desiredSpeed

    def getDesiredAngle(self):
        return self.__desiredAngle
