from src.controll.PIDSpeedLowController import *

class PIDTrajectoryController(PIDSpeedController):

    def __init__(self,  _P, _I, _D, _updateTime, _motor, _jointLock, _pCount):
        super().__init__(_P, _I, _D, _updateTime, _motor, _jointLock, _pCount)
        self._P = _P
        self._I = _I
        self._D = _D
        self._p = 0
        self._i = 0
        self._d = 0
        self._currentAngleError = 0
        self._currentSpeedError
        self._desiredAngle = 0
        self._desiredSpeed = 0

    def startPIDController(self):
        while True:
            self.stateJoint.stateUpdate()
            if self._power:
                if(self._angleMode and (not self._inPosition())) or (not self._angleMode):
                    lasttime = time()
                    self._firstSpeedError = self._currentSpeedError
                    self._currentSpeedError = self._desiredSpeed - self.stateJoint.getCurrentSpeed()
                    self._currentAngleError = self._desiredAngle-self.stateJoint.getCurrentAngle()
                    self._p = (self._currentSpeedError+self._currentAngleError) * self._P
                    self._i += (self._currentSpeedError + self._currentAngleError) * self._updateTime * self._I
                    self._u = (self._p + self._i)
                    if abs(self._u) > 100:
                        self._u = copysign(1, self._u) * 100
                    self._motor.run_direct(duty_cycle_sp=self._u)
                    currenttime = time()
                    sleep(self._updateTime - (currenttime - lasttime))
            else:
                self._p = 0
                self._i = 0
                self._d = 0
                self._currentAngleError = 0
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
