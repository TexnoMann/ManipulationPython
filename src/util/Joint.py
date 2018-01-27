from time import sleep


from threading import Thread, Lock

DT = 0.010

class Joint:
    def __init__(self, controllerJoint, stateJoint):
        self.controllerJoint = controllerJoint
        self.stateJoint = stateJoint
        self.controllerJoint.getMotor().reset()



