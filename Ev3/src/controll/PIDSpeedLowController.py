from ev3dev.ev3 import *
from time import *
from math import pi
from math import copysign
from threading import Thread, Lock
from src.state.State import *


# New thread
from src.state.State import StateJoint


class PIDSpeedController:

    def __init__(self, _P, _I, _D, _updateTime, _motor, _state, __hardResetTouch):
        self.__hardResetTouch = __hardResetTouch
        self.__controllerOn = True
        self.stateJoint = _state
        self._jointLock = self.stateJoint.jointLock
        self._P = _P
        self._I = _I
        self._D = _D
        self._updateTime = _updateTime
        self._motor = _motor
        self._p = 0
        self._i = 0
        self._desiredSpeed = 0
        self._desiredAngle = 0
        self._currentSpeedError = 0
        self._firstSpeedError = 0
        self._u = 0
        self._uA = 0
        self._times = 0
        self._positionError = 0.04
        self._power = False
        self._angleMode = False
        self._holding = False
        self.threadController = Thread(target=self.startPIDController)
        self.threadController.setDaemon(True)
        self.threadController.start()

    def startThread(self):
        self.__controllerOn=True
        self.threadController.__init__(target=self.startPIDController)
        self.threadController.setDaemon(True)
        self.threadController.start()

    def setDesiredSpeed(self, desiredSpeed):
        self._jointLock.acquire()
        self._desiredSpeed = desiredSpeed
        self._jointLock.release()

    def setDesiredAngle(self, desiredAngle):
        self._jointLock.acquire()
        self._desiredAngle = desiredAngle
        self._jointLock.release()

    def startPIDController(self):
        while True:
            if self.__controllerOn:
                self.stateJoint.stateUpdate()
                if self._power:
                    if(self._angleMode and (not self._inPosition())) or (not self._angleMode):
                        lasttime = time()
                        self._firstSpeedError = self._currentSpeedError
                        self._currentSpeedError = (self._desiredSpeed - self.stateJoint.getCurrentSpeed())
                        self._p = self._currentSpeedError * self._P
                        self._i += self._currentSpeedError * self._updateTime * self._I
                        self._u = (self._p + self._i)
                        if abs(self._u) > 100:
                            self._u = copysign(1, self._u) * 100
                        self._motor.run_direct(duty_cycle_sp=self._u*self.stateJoint.inverted)
                        currenttime = time()
                        sleep(self._updateTime - (currenttime - lasttime))
                else:
                    self._p = 0
                    self._i = 0
                    self._currentSpeedError = 0
                    self._firstSpeedError = 0
                    self._desiredSpeed = 0
                    self._u = 0
                    self._times = 0
                    self.stateJoint.removeSpeed()

                    # Holding Joint
                    if self._holding:
                        self._motor.stop(stop_action='hold')
                    else:
                        self._motor.stop(duty_cycle_sp='0')
                    sleep(self._updateTime)
            else: break
        self.__controllerOn=False

    def moveForever(self):
        self._jointLock.acquire()
        self._power = True
        self._angleMode = False
        self._jointLock.release()

    def moveToAngle(self):
        self._jointLock.acquire()
        self._power = True
        self._angleMode = True
        self._jointLock.release()

    def stop(self, holding):
        self._jointLock.acquire()
        self._power = False
        self._holding = holding
        self._jointLock.release()

    def off(self):
        self._jointLock.acquire()
        self.__controllerOn = False
        self._jointLock.release()

    def on(self):
        self.startThread()

    def getMotor(self):
        return self._motor

    def _inPosition(self):
        if abs(self._desiredAngle-self.stateJoint.getCurrentAngle()) <= self._positionError:
            self._power = False
            self.stop(True)
            return True
        else:
            return False

    def resetController(self):
        self._p = 0
        self._i = 0
        self._currentSpeedError = 0
        self._firstSpeedError = 0
        self._desiredSpeed = 0
        self._u = 0
        self._uA = 0
        self._times = 0
        self.stateJoint.removeSpeed()
        self.stateJoint.resetState()
        self.getMotor().reset()
