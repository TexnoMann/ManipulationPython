from time import sleep


from threading import Thread, Lock

DT = 0.010

class Joint:
    def __init__(self, controllerJoint):
        self.controllerJoint = controllerJoint
        self.controllerJoint.getMotor().reset()



