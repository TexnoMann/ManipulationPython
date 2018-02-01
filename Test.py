from src.util.JointManager import *

def main():
    J0.moveToAngle(0.8, 0.02)
    J1.moveToAngle(0.8, 0.02)
    J2.moveToAngle(1.5, -3)

    sleep(8)
    J0.stop(True)
    J1.stop(True)
    J2.stop(True)
    sleep(1)

if __name__ == "__main__" :
    main()