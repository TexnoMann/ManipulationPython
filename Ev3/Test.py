from src.numKinematic.OZK import *
from src.numKinematic.PZK import *
from src.numKinematic.VelocityKinematic import *

def main():
    a = [0.055, 0.15, 0.20]
    d = [0.17, 0.0, 0.0]
    v = VelocityOZK(a, d)
    print(str(v.getLinearSpeed([0, pi/2, 0], [0, -pi/2, 0])))





if __name__ == "__main__" :
    main()