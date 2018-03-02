from time import sleep

from threading import Thread, Lock

DT = 0.010


class Joint:

    def __init__(self, controllerJoint, __invertMotor):
        self.__invertMotor = __invertMotor
        self.controllerJoint = controllerJoint
        self.controllerJoint.getMotor().reset()

    def moveForever(self, speed):
        self.controllerJoint.setDesiredSpeed(speed*self.__invertMotor)
        self.controllerJoint.moveForever()

    def moveToAngle(self, speed, angle):
        if angle < self.getCurrentAngle():
            speed = -speed
        self.controllerJoint.setDesiredSpeed(speed*self.__invertMotor)
        self.controllerJoint.setDesiredAngle(angle*self.__invertMotor)
        self.controllerJoint.moveToAngle()

    def getCurrentAngle(self):
        return self.controllerJoint.stateJoint.getCurrentAngle()*self.__invertMotor

    def getCurrentSpeed(self):
        return self.controllerJoint.stateJoint.getCurrentSpeed()*self.__invertMotor

    def stop(self, holding):
        self.controllerJoint.stop(holding)

    def isMoving(self):
        return not self.controllerJoint.stateJoint.isStalled()

    def reset(self):
        self.stop(False)
        self.controllerJoint.resetController()


