from src.util.JointManager import *

def main():

    for i in range(100):
        xyz = manipulator.getPosition()
        print(str(xyz[0])+"    "+ str(xyz[1])+"    "+ str(xyz[2])+"    ")
        sleep(1)


if __name__ == "__main__" :
    main()