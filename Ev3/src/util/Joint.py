from time import sleep

from threading import Thread, Lock



class Joint:

    def __init__(self, speedControllerJoint):
        self.speedControllerJoint = speedControllerJoint
        self.__mode = False
        self.speedControllerJoint.getMotor().reset()

    def moveForever(self, speed):
        self.speedControllerJoint.setDesiredSpeed(speed)
        self.speedControllerJoint.moveForever()

    def moveToAngle(self, angle, speed):
        if angle < self.getCurrentAngle():
            speed = -speed
        self.speedControllerJoint.setDesiredSpeed(speed)
        self.speedControllerJoint.setDesiredAngle(angle)

        self.speedControllerJoint.moveToAngle()

    def getCurrentAngle(self):
        return self.speedControllerJoint.stateJoint.getCurrentAngle()

    def getCurrentSpeed(self):
        return self.speedControllerJoint.stateJoint.getCurrentSpeed()

    def stop(self, holding):
        self.speedControllerJoint.stop(holding)

    def isMoving(self):
        return not self.speedControllerJoint.stateJoint.isStalled()

    def reset(self):
        self.stop(False)
        self.speedControllerJoint.resetController()

    def controllerOff(self):
        self.speedControllerJoint.off()

    def controllerOn(self):
        self.speedControllerJoint.on()
