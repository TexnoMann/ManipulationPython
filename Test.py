from src.util.JointManager import *
from src.numKinematic.PZK import *

def main():
    for i in range(100):
        theta=[J0.controllerJoint.stateJoint.getCurrentAngle(), J1.controllerJoint.stateJoint.getCurrentAngle(), J2.controllerJoint.stateJoint.getCurrentAngle()]
        x_y_z = fKinematics.getXYZ(theta)
        print("X:"+str(x_y_z[0]) + "      ", "Y:" + str(x_y_z[1])+"      ", "Z:" + str(x_y_z[2])+"      ")
        sleep(1)

if __name__ == "__main__" :
    main()