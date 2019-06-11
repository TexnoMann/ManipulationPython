from src.logger.Logger import *
from src.util.TrajectoryPlaning import *
from src.numKinematic.SolverKinematic import *


class Manipulator:
    def __init__(self, joints, trajectoryController, DHParameters, calibration):
        # Configuration manipulator
        self.__DHParameters = DHParameters
        self.calibration=calibration
        self.__trjController = trajectoryController
        self.__controllerTrjMode = False
        self.__defaultMotionSpeed = [0.7, 0.7, 0.7]
        self.joints = joints
        self.__solverKinematic = SolverKinematic(self.__DHParameters)
        sleep(1)
        self.moveHome()
        sleep(1)
        for j in range(len(self.joints)):
            self.__trjController.stateMan[j].setCalibCoord(self.calibration.startAngle[j])

    def setDefaultMotionSpeed(self, speed):
        self.__defaultMotionSpeed = speed

    def setJointAngle(self, q, speed):
        if self.__controllerTrjMode:
            self.__controllerTrjMode = False
            self.__trjController.stop(True)
        self.joints[0].moveToAngle(q[0], speed[0])
        self.joints[1].moveToAngle(q[1], speed[1])
        self.joints[2].moveToAngle(q[2], speed[2])

    def getJointAngle(self):
        q = [0, 0, 0]
        q[0] = self.joints[0].getCurrentAngle()
        q[1] = self.joints[1].getCurrentAngle()
        q[2] = self.joints[2].getCurrentAngle()
        return q

    def getJointSpeed(self):
        s = [0, 0, 0]
        s[0] = self.joints[0].getCurrentSpeed()
        s[1] = self.joints[1].getCurrentSpeed()
        s[2] = self.joints[2].getCurrentSpeed()
        return s

    def getPosition(self):
        xyz = self.__solverKinematic.getXYZ(self.getJointAngle())
        return xyz

    def setPosition(self, xyz, speed):
        q = self.__solverKinematic.getAngle(xyz[0], xyz[1], xyz[2])
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

    # Trajectory function:

    def __goToStartPointTrj(self, startPoint):
        print(startPoint)
        self.setJointAngle(startPoint, self.__defaultMotionSpeed)
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
        self.__trjController.moveOnTrajectory(way)
        self.__trjController.waitFinishMoving()
        for j in self.joints:
            j.controllerOn()
        self.__controllerTrjMode = False
