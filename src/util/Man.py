from src.numKinematic.PZK import *
from src.numKinematic.OZK import *

class Manipulator():
    def __init__(self, joints):

        # Configuration manipulator
        self.__InstrL = 0
        self.__a = [0.055, 0.15, 0.14 + self.__InstrL]
        self.__d = [0.17, 0.0, 0.0]
        self.joints = joints
        self.__fKinematic = ForwardKinematic(self.__a, self.__d)
        self.__iKinematic = InverseKinematic(self.__a, self.__d)


    def getPosition(self):
        theta = [self.joints[0].getCurrentAngle(), self.joints[1].getCurrentAngle(), self.joints[2].getCurrentAngle()]
        xyz = self.__fKinematic.getXYZ(theta)
        return xyz

    def __getAngle(self, xyz):
        q = self.__iKinematic.getAngle(xyz[0], xyz[1], xyz[2])
        return q

    def setPosition(self, xyz):
        q = self.__getAngle(xyz)
        self.joints[0].moveToAngle(1, q[0])
        self.joints[1].moveToAngle(1, q[1])
        self.joints[2].moveToAngle(1, q[2])