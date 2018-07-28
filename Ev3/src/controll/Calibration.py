from src.util.DeviceManager import *
from time import *


# StartAngles - three metrics
# [-1.3823    2.1433   -2.7945]

class Calibration:
    def __init__(self, __Joints, __side, initAngle):
        self.__side = __side
        self.__defaultCheckTime = 0.1
        self.__Joints = __Joints
        assert (len(self.__Joints) == len(self.__side)), "Side count error!"
        self.startAngle = list(0 for i in range(0, len(self.__Joints)))
        for i in range(len(self.__Joints)):
            self.startAngle[i] = initAngle[i] * self.__Joints[i].speedControllerJoint.stateJoint.inverted
        self.__defaultSpeed = 0.6
        self.__currentCalibrationState = False

    def setDefaultCheckTime(self, defaultCheckTime):
        self.__defaultCheckTime = defaultCheckTime

    def setDefaultSpeed(self, defaultSpeed):
        self.__defaultSpeed = defaultSpeed

    def calib(self):
        self.__currentCalibrationState = True
        for jnumber in range(len(self.__Joints)):
            self.__Joints[jnumber].moveForever(self.__defaultSpeed * self.__side[jnumber])
        sleep(0.8)

        while (self.__currentCalibrationState):
            self.__currentCalibrationState=False
            for joint in self.__Joints:
                self.__currentCalibrationState = self.__currentCalibrationState or joint.isMoving()
            for jnumber in range(len(self.__Joints)):
                if not self.__Joints[jnumber].isMoving(): self.__Joints[jnumber].stop(False)
            sleep(self.__defaultCheckTime)
        sleep(0.2)

        for jnumber in range(len(self.__Joints)):
            self.__Joints[jnumber].stop(False)
        for jnumber in range(len(self.__Joints)):
            self.__Joints[jnumber].reset()
        print("Calibration Complete")
        # Sound.speak("Calibration Complete").wait()
