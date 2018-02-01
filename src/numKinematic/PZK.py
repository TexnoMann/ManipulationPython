from math import *

class ForwardKinematic():
    def __init__(self, __a, __d):
        self.__a = __a
        self.__d = __d

    def __getX(self, theta):
        X = self.__a[0] * cos(theta[0]) + self.__d[1] * sin(theta[0]) + self.__d[2] * sin(theta[0]) + self.__a[1] * cos(theta[0]) * cos(theta[1]) + self.__a[2] * cos(theta[0]) * cos(theta[1]) * cos(theta[2]) - self.__a[2] * cos(theta[0]) * sin(theta[1]) * sin(theta[2])
        return X

    def __getY(self, theta):
        Y = self.__a[0] * sin(theta[0]) - self.__d[2] * cos(theta[0]) - self.__d[1] * cos(theta[0]) + self.__a[1] * cos(theta[1]) * sin(theta[0]) + self.__a[2] * cos(theta[1]) * cos(theta[2]) * sin(theta[0]) - self.__a[2] * sin(theta[0]) * sin(theta[1]) * sin(theta[2])
        return Y

    def __getZ(self, theta):
        Z = self.__d[0] + self.__a[1]*sin(theta[1]) + self.__a[2]*cos(theta[1])*sin(theta[2]) + self.__a[2]*cos(theta[2])*sin(theta[1])
        return Z

    def getXYZ(self, theta):
        xyz = [self.__getX(theta), self.__getY(theta), self.__getZ(theta)]
        return xyz
