
from ev3dev.ev3 import  *
from threading import *
from multiprocessing import *
from time import*
import serial

class Logger():
    def __init__(self, __man, __logTime, withcurrent=False):
        self.__motionlogFileName="motion.log"
        self.__motionLog = open(self.__motionlogFileName, "w")
        self.__man = __man
        self.__angle = [0, 0, 0]
        self.__speed = [0, 0, 0]
        self.__position = [0, 0, 0]
        self.__withCurrentFlag=withcurrent
        if (self.__withCurrentFlag):
            self.__serialCurrentSensor = serial.Serial('/dev/ttyUSB0', 115200, timeout=1)
        self.__current = [0, 0, 0]
        self.__logTime = __logTime
        self.__goLog=True
        self.__thread = Thread(target=self.loopLog)
        self.__thread.setDaemon(True)
        self.__startTime = time()


    def putMessage(self):
        self.__speed = self.__man.getJointSpeed()
        self.__angle = self.__man.getJointAngle()
        self.__position = self.__man.getPosition()
        if(self.__withCurrentFlag):
            current_msg = self.__serialCurrentSensor.readline()
            self.__current = list(map(float, current_msg.split()))
        else:
            self.__current = [0, 0, 0]
        msg = self.__angle + self.__speed + self.__current + [time()-self.__startTime]
        self.__motionLog.writelines("%s " % i for i in msg)
        self.__motionLog.writelines("\n")
        #print(msg)

    def loopLog(self):
        while(self.__goLog):
            self.putMessage()
            sleep(self.__logTime)

    def startLogger(self):
        print("[Logger] Logger is started!")
        self.__thread.start()

    def stopLogger(self):
        print("[Logger] Logger is stopped!")
        self.__goLog=False