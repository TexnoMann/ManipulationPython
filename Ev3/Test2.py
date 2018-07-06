from ev3dev.ev3 import *
from math import copysign,pi

from time import *

#Umax=6.89V

def main():
    motor0=LargeMotor(OUTPUT_C)
    motor0.reset()
    file = open("dataAngleMaxMoments.out", "w")
    sleep(4)
    for u in range(20, 100, 10):
        input("Go")
        maxaccel=0
        speed=0
        accel=0
        Sound.tone(1000, 100).wait()
        motor0.reset()
        firsttime=time()
        motor0.run_direct(duty_cycle_sp=u)
        while motor0.position < 2000 :
            maxaccel=max(maxaccel,)
        motor0.stop(duty_cycle_sp=0)
        print("Time:" + str(time()-firsttime))
main()