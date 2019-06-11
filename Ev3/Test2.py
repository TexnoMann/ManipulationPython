from ev3dev.ev3 import *
from math import copysign,pi

from time import *

#Umax=6.89V

def main():
    motor0=LargeMotor(OUTPUT_C)
    motor0.reset()
    Ps=PowerSupply()
    while True:
        print(Ps.measured_amps())
main()
