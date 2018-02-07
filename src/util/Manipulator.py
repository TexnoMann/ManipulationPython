from src.util.Joint import *
from src.numKinematic.OZK import *
from src.numKinematic.PZK import *

class Manipulator():
    def __init__(self, joints):
        # Configuration manipulator
        self.__InstrL = 0
        self.__a = [0.055, 0.15, 0.14 + self.__InstrL]
        self.__d = [0.17, 0.0, 0.0]
        self.joints = joints
        self.__inverseKinematic = InverseKinematic(self.__a, self.__d)
        self.__forwardKinematic = ForwardKinematic(self.__a, self.__d)

    def setJointAngle(self, speed, q):
        self.joints[0].moveToAngle(speed, q[0])
        self.joints[1].moveToAngle(speed, q[1])
        self.joints[2].moveToAngle(speed, q[2])
        self.waitMoving()

    def getJointAngle(self):
        q = [self.joints[0].getCurrentAngle(), self.joints[1].getCurrentAngle(), self.joints[2].getCurrentAngle()]
        return q

    def getPosition(self):
        xyz = self.__forwardKinematic.getXYZ(self.getJointAngle())
        return  xyz

    def setPosition(self, speed, xyz):
        q = self.__inverseKinematic.getAngle(xyz[0], xyz[1], xyz[2])
        self.setJointAngle(speed, q)



    def waitMoving(self):
        sleep(0.3)
        while self.joints[0].isMoving() or self.joints[1].isMoving() or self.joints[2].isMoving():
            print(str(self.joints[0].isMoving()) + " " + str(self.joints[1].isMoving()) + " " + str(self.joints[2].isMoving()))
            sleep(0.001)