
import src.controll.PIDControll as PIDControll
from threading import Thread, Lock


class ControllerJoint:

    def __init__(self, __P, __I, __D, __updateTime, __motor):
        self.__controller = PIDControll.PIDSpeedController(__P, __I, __D, __updateTime, __motor,)
        self.__desiredSpeed = 0
        self.__desiredAngle = 0
        self.__currentAngle = 0
        self.power = 0

    def setDesiredSpeed(self, desiredSpeed):
        self.__desiredSpeed = desiredSpeed
        self.__controller.setDesiredSpeed(self.__desiredSpeed)

    def setDesiredAngle(self, desiredAngle):
        self.__desiredAngle = desiredAngle

    def getDesiredSpeed(self):
        return self.__desiredSpeed

    def getDesiredAngle(self):
        return self.__desiredAngle

    def sendCurrentAngle(self, angle):
        self.__controller.setCurrentAngle(angle)

    def moveStart(self):
        self.__controller.move()

    def moveStop(self, holding):
        self.__controller.stop(holding)
