from src.util.DeviceManager import *

# StartAngles - three metrics
#[-1.3823    2.1433   -2.7945]



class Calibration():
    def __init__(self, __Joints):
        self.startAngle = [-1.3823,   2.1433,   -2.7945]
        self.__Joints = __Joints
        self.defaultSpeed = 0.6
        self.__currentCalibrationState = False

    def calib(self):
        self.__currentCalibrationState = True
        self.__Joints[0].moveForever(-self.defaultSpeed)
        self.__Joints[1].moveForever(self.defaultSpeed)
        self.__Joints[2].moveForever(-self.defaultSpeed)
        print("Calibrated Complete")
        Sound.speak("Calibration Complete").wait()

        sleep(0.5)
        while(self.__currentCalibrationState):
            self.__currentCalibrationState = self.__Joints[0].isMoving() or self.__Joints[1].isMoving() or self.__Joints[2].isMoving()
            if not self.__Joints[0].isMoving(): self.__Joints[0].stop(False)
            if not self.__Joints[1].isMoving(): self.__Joints[1].stop(False)
            if not self.__Joints[2].isMoving(): self.__Joints[2].stop(False)
            sleep(0.1)
        sleep(0.6)
        self.__Joints[0].stop(False)
        self.__Joints[1].stop(False)
        self.__Joints[2].stop(False)
        self.__Joints[0].reset()
        self.__Joints[1].reset()
        self.__Joints[2].reset()