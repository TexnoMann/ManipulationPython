
from ev3dev.ev3 import  *
from threading import *
from multiprocessing import *

class Logger():
    def __init__(self, lcdFlag):
        self.__lcdFlag = lcdFlag
        if self.__lcdFlag:
            self.__lcd = Screen()
        self.__currentMessage = "None"
        self.__lastMessage = "None"
        self.__queue = Queue()
        self.__threadLogger = Thread(target=self.logThread())
        self.__threadLogger.setDaemon(True)
        self.__threadLogger.start()

    def logThread(self):
        while True:
            if not self.__queue.empty():
                if self.__lcdFlag:
                    self.__lcd.draw.text((10, 10), self.__queue.get_nowait())

    def putMessage(self, message):
        self.__lastMessage = self.__currentMessage
        self.__currentMessage = message
        if self.__currentMessage != self.__lastMessage:
            self.__queue.put_nowait(self.__currentMessage)
