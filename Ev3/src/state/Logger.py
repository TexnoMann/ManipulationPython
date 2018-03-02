
from ev3dev.ev3 import  *
from threading import *
from multiprocessing import *
from time import*
from src.util.Manipulator import *

class Logger():
    def __init__(self, __man, __logTime):
        self.__motionlogFileName="motion.log"
        self.__motionLog = open(self.__motionlogFileName, "w")
        self.__man = __man
        self.__angle = [0, 0, 0]
        self.__speed = [0, 0, 0]
        self.__position = [0, 0, 0]
        self.__logTime = __logTime
        self.__thread = Thread(target=self.loopLog)
        self.__thread.setDaemon(True)


    def putMessage(self):
        self.__speed = self.__man.getJointSpeed()
        self.__angle = self.__man.getJointAngle()
        self.__position = self.__man.getPosition()
        self.__motionLog.write("Speed: " + self.__speed + "  " + "Angle: " + self.__angle  + "  " + "Position: " + self.__position + "  " + "Time: " + time + '\n')

    def loopLog(self):
        while(True):
            self.putMessage()
            sleep(self.__logTime)

    def startLogger(self):
        self.__thread.start()