from src.util.Joint import *
from src.numKinematic.OZK import *
from src.numKinematic.PZK import *
from src.controll.Calibration import *


class Manipulator():
    def __init__(self, joints):
        # Configuration manipulator
        self.__InstrL = 0.06
        self.__a = [0.055, 0.15, 0.20]
        self.__d = [0.17, 0.0, 0.0]
        self.joints = joints
        self.__inverseKinematic = InverseKinematic(self.__a, self.__d)
        self.__forwardKinematic = ForwardKinematic(self.__a, self.__d)
        self.calibration = Calibration(joints)
        self.__logger = Logger(0.2)

    def setJointAngle(self, speed, q):
        self.joints[0].moveToAngle(speed, q[0]-self.calibration.startAngle[0])
        self.joints[1].moveToAngle(speed, q[1]-self.calibration.startAngle[1])
        self.joints[2].moveToAngle(speed, q[2]-self.calibration.startAngle[2])
        self.waitMoving()

    def getJointAngle(self):
        q = [0, 0, 0]
        q[0]=self.joints[0].getCurrentAngle()+self.calibration.startAngle[0]
        q[1]=self.joints[1].getCurrentAngle()+self.calibration.startAngle[1]
        q[2]=self.joints[2].getCurrentAngle()+self.calibration.startAngle[2]
        return q

    def getPosition(self):
        xyz = self.__forwardKinematic.getXYZ(self.getJointAngle())
        return  xyz

    def setPosition(self, speed, xyz):
        q = self.__inverseKinematic.getAngle(xyz[0], xyz[1], xyz[2])
        self.setJointAngle(speed, q)
        self.waitMoving()

    def moveHome(self):
        self.calibration.calib()

    def startLogger(self):
        self.__logger.startLogger()


    def waitMoving(self):
        sleep(0.3)
        while self.joints[0].isMoving() or self.joints[1].isMoving() or self.joints[2].isMoving():
            sleep(0.1)