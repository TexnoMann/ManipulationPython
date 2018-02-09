from src.numKinematic.OZK import *
from src.numKinematic.PZK import *

def main():
    k=InverseKinematic([0.055, 0.15, 0.14], [0.17, 0.0, 0.0])
    f=ForwardKinematic([0.055, 0.15, 0.14], [0.17, 0.0, 0.0])
    print(k.getAngle(0.1, 0.1, 0.1))
    print(f.getXYZ(k.getAngle(0.1, 0.1, 0.1)))





if __name__ == "__main__" :
    main()