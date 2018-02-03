from time import sleep

from threading import Thread, Lock

DT = 0.010


class Joint:
    def __init__(self, controllerJoint, startPosition, __invertMotor):
        self.__invertMotor = __invertMotor
        self.startPosition = startPosition
        self.controllerJoint = controllerJoint
        self.controllerJoint.getMotor().reset()

    def getStartPosition(self):
        return self.startPosition

    def moveToAngle(self, speed, angle):
        self.controllerJoint.setDesiredSpeed(abs(speed))
        self.controllerJoint.setDesiredAngle(angle*self.__invertMotor)
        self.controllerJoint.moveToAngle()

    def moveForever(self, speed):
        self.controllerJoint.setDesiredSpeed(speed)
        self.controllerJoint.moveForever()

    def stop(self, hold):
        self.controllerJoint.stop(hold)

    def getCurrentAngle(self):
        return self.controllerJoint.stateJoint.getCurrentAngle()*self.__invertMotor

    def getCurrentSpeed(self):
        return self.controllerJoint.stateJoint.getCurrentSpeed()*self.__invertMotor
