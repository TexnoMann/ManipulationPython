from math import *

class DirectKinematic():
    def __init__(self,__a,__d):
        self.__a=__a
        self.__d=__d


    def __getX(self,theta):
        X=self.__a[0] * cos(theta[0]) + self.__d[1] * sin(theta[0]) + self.__d[2] * sin(theta[0]) + self.__a[1] * cos(theta[0]) * cos(theta[1]) + self.__a[2] * cos(theta[0]) * cos(theta[1]) * cos(theta[2]) - self.__a[2] * cos(theta[0]) * sin(theta[1]) * sin(theta[2])
        return X

    def __getY(self,theta):
        a0 * sin(theta0) - d2 * cos(theta0) - d1 * cos(theta0) + a1 * cos(theta1) * sin(theta0) + a2 * cos(theta1) * cos(theta2) * sin(theta0) - a2 * sin(theta0) * sin(theta1) * sin(theta2)