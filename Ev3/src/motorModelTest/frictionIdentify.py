from ev3dev.ev3 import *
from math import copysign, pi, sin

from time import *

def main():
    maxV = 7.66
    motor0=LargeMotor(OUTPUT_A)
    motor0.reset()
    file = open("frictionTestMotor0.out", "w")
    sleep(1)
    times = 0
    angle = 0
    PCount = 5.5
    firstTime = time()
    while times <= 20:
        u = 100*sin(times)
        motor0.run_direct(duty_cycle_sp=u)
        angle = motor0.position*pi/180.0/PCount
        s=str(angle) + " " + str(u/100*maxV) + " " + str(times) +"\n"
        file.writelines(s)
        times = time()-firstTime

    motor0.stop(duty_cycle_sp=0)
main()