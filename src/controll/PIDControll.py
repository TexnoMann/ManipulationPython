from ev3dev.ev3 import *
from time import time
from math import pi
from math import copysign

DT = 0.015
Pk = 3
Ik = 50
MaxPower = PowerSupply.measured_volts


def main():
    motor=LargeMotor(OUTPUT_A)
    p = 0
    i = 0
    startTime=time()
    desiredSpeed=1.0
    currentSpeed=0
    currentAngle=0
    firstAngle=0
    firstSpeed=0
    currentSpeedError=0
    firstSpeedError=0
    u = 0

    motor.reset()

    while motor.position < 120:

        firstAngle = currentAngle
        currentAngle = motor.position*pi/180.0
        firstSpeed=currentSpeed
        currentSpeed=(currentAngle-firstAngle)*DT
        firstSpeedError=currentSpeedError
        currentSpeedError=desiredSpeed-currentSpeed

        p = currentSpeedError*Pk
        i += currentSpeedError*DT*Ik
        u = (p+i)
        if abs(u) > 100:
            u = copysign(1, u)*100
        motor.run_direct(duty_cycle_sp=u)
        time.sleep(DT)
