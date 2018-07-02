from src.util.Joint import *
from src.numKinematic.OZK import *
from src.numKinematic.PZK import *
from src.controll.Calibration import *
from src.state.Logger import *
from src.util.TrajectoryPlaning import *





class Manipulator():
    def __init__(self, joints, trajectoryController):
        # Configuration manipulator
        self.__trjController = trajectoryController
        self.__controllerTrjMode = False
        self.__InstrL = 0.06
        self.__a = [0.055, 0.15, 0.20]
        self.__d = [0.17, 0.0, 0.0]
        self.__defaultMotionSpeed = [0.6, 0.6, 0.6]
        self.joints = joints
        self.__inverseKinematic = InverseKinematic(self.__a, self.__d)
        self.__forwardKinematic = ForwardKinematic(self.__a, self.__d)
        self.calibration = Calibration(joints)

    def setJointAngle(self, q, speed):
        if self.__controllerTrjMode:
            self.__controllerTrjMode = False
            self.__trjController.stop(True)
        self.joints[0].moveToAngle(q[0] - self.calibration.startAngle[0], speed[0])
        self.joints[1].moveToAngle(q[1] - self.calibration.startAngle[1], speed[1])
        self.joints[2].moveToAngle(q[2] - self.calibration.startAngle[2], speed[2])

    def getJointAngle(self):
        q = [0, 0, 0]
        q[0] = self.joints[0].getCurrentAngle()+self.calibration.startAngle[0]
        q[1] = self.joints[1].getCurrentAngle()+self.calibration.startAngle[1]
        q[2] = self.joints[2].getCurrentAngle()+self.calibration.startAngle[2]
        return q

    def getJointSpeed(self):
        s = [0, 0, 0]
        s[0] = self.joints[0].getCurrentSpeed()
        s[1] = self.joints[1].getCurrentSpeed()
        s[2] = self.joints[2].getCurrentSpeed()
        return s

    def getPosition(self):
        xyz = self.__forwardKinematic.getXYZ(self.getJointAngle())
        return  xyz

    def setPosition(self, xyz, speed):
        q = self.__inverseKinematic.getAngle(xyz[0], xyz[1], xyz[2])
        self.setJointAngle(q, speed)

    def moveHome(self):
        if self.__controllerTrjMode:
            self.__controllerTrjMode = False
            self.__trjController.stop()
        self.calibration.calib()

    def startLogger(self):
        self.__logger.startLogger()

    def waitMoving(self):
        sleep(0.3)
        while self.joints[0].isMoving() or self.joints[1].isMoving() or self.joints[2].isMoving():
            sleep(0.1)

    def getCalibrationCoordinats(self):
        return self.calibration.startAngle

#Trajectory function:

    def __goToStartPointTrj(self, startPoint):
        print(startPoint)
        self.setJointAngle(startPoint, [0.7, 0.7, 0.7])
        self.waitMoving()
        sleep(5)

    def startTrajectoryFollow(self, trajectoryFileName):
        trj = TrajectoryPlaning(trajectoryFileName)
        print("startCoords:" + str(trj.startCoords) + "\n")
        way = trj.readTrajectory()
        self.__goToStartPointTrj(list(trj.startCoords[0]))
        print(self.getJointAngle())

        if not self.__controllerTrjMode:
            for j in self.joints:
                j.controllerOff()
            self.__controllerTrjMode = True
        print("go")
        sleep(5)
        self.__trjController.setCalibCoords(self.calibration.startAngle)
        self.__trjController.moveOnTrajectory(way)
        self.__trjController.waitFinishMoving()