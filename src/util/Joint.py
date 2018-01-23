from time import sleep
from src.controll.Controller import *

from threading import Thread

DT = 0.010

class Joint:
    def __init__(self, controllerJoint, stateJoint):
        self.controllerJoint = controllerJoint
        self.stateJoint = stateJoint
        self.__messageThread = Thread(target=self.jointMove)
        self.__messageThread.setDaemon(True)
        self.__messageThread.start()

    def jointMove(self):
        while True:
            self.controllerJoint.sendCurrentAngle(self.stateJoint.getCurrentAngle())
            sleep(DT)
