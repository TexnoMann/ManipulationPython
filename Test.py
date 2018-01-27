from src.util.JointManager import *

def main():
    J1.controllerJoint.setDesiredSpeed(0.4)
    J2.controllerJoint.setDesiredSpeed(0.6)
    J1.controllerJoint.move()
    J2.controllerJoint.move()


    sleep(3)
    J1.controllerJoint.stop(True)
    J2.controllerJoint.stop(True)
    sleep(1)

if __name__ == "__main__" :
    main()