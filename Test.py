from src.util.JointManager import *

def main():
    J0.controllerJoint.setDesiredSpeed(0.4)
    J1.controllerJoint.setDesiredSpeed(0.3)
    J2.controllerJoint.setDesiredSpeed(0.3)

    J0.controllerJoint.setDesiredAngle(1.5)
    J1.controllerJoint.setDesiredAngle(1.5)
    J2.controllerJoint.setDesiredAngle(1.5)

    J0.controllerJoint.moveToAngle()
    J1.controllerJoint.moveToAngle()
    J2.controllerJoint.moveToAngle()


    sleep(8)
    J0.controllerJoint.stop(True)
    J1.controllerJoint.stop(True)
    J2.controllerJoint.stop(True)
    sleep(1)

if __name__ == "__main__" :
    main()