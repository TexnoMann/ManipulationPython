from ev3dev.ev3 import *
from math import copysign,pi

from time import *

P=3.63
I=50.3
updateTime=0.050

def main():
    currenttime=0
    firstAngle=0
    desiredSpeed = 0.4
    currentSpeed=0
    currentAngle=0
    firstSpeed=0
    currentSpeedError = 0
    p=0
    i=0
    u=0
    motor= LargeMotor(OUTPUT_A)
    lcd= Screen()

    motor.reset()
    while True:
        lasttime=time()
        firstAngle = currentAngle
        currentAngle = motor.position*pi/180
        firstSpeed = currentSpeed
        currentSpeed = (currentAngle-firstAngle)/updateTime
        firstSpeedError = currentSpeedError
        currentSpeedError = desiredSpeed-currentSpeed

        p = currentSpeedError*P
        i += currentSpeedError*updateTime*I
        u = (p+i)
        if abs(u) > 100:
            u = copysign(1, u)*100
        motor.run_direct(duty_cycle_sp=u)
        currenttime = time()
        sleep(updateTime-(currenttime-lasttime))


main()