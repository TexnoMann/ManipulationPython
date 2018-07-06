from math import *

class SolverKinematic:

    def __init__(self, __DHaram):
        self.__a = __DHaram.getA()
        self.__d = __DHaram.getD()
        self.__q = list(0 for i in range(0, len(self.__d)))
        self.__xyz = [0, 0, 0]
        self.__orientationAngle=[0, 0, 0]

    def getAngle(self, X03, Y03, Z03):
        self.__q[0] = atan2(Y03, X03)

        X01 = self.__a[0]
        Z01 = self.__d[0]
        Y01 = self.__a[0]*sin(self.__q[0])
        X13 = sqrt(pow(X03, 2)+pow(Y03, 2))-X01
        Y13 = Z03-Z01

        b2 = pow(X13, 2)
        c2 = pow(Y13, 2)
        b = X13
        c = Y13
        d2 = b2 + c2

        cq2 = (d2 - pow(self.__a[1], 2) - pow(self.__a[2], 2))/(2*self.__a[1]*self.__a[2])
        self.__q[2] = atan2(-sqrt(1-pow(cq2, 2)), cq2)
        self.__q[1] = -(pi/2-(atan2(c, b) - atan2(self.__a[2]*sin(self.__q[2]), self.__a[1]+cq2*self.__a[2])))

        return self.__q

    def __getX(self, theta):
        X = self.__a[0] * cos(theta[0]) + self.__d[1] * sin(theta[0]) + self.__d[2] * sin(theta[0]) + self.__a[1] * cos(
            theta[0]) * -sin(theta[1]) + self.__a[2] * cos(theta[0]) * -sin(theta[1]) * cos(theta[2]) - self.__a[
                2] * cos(theta[0]) * cos(theta[1]) * sin(theta[2])
        return X

    def __getY(self, theta):
        Y = self.__a[0] * sin(theta[0]) - self.__d[2] * cos(theta[0]) - self.__d[1] * cos(theta[0]) + self.__a[
            1] * -sin(theta[1]) * sin(theta[0]) + self.__a[2] * -sin(theta[1]) * cos(theta[2]) * sin(theta[0]) - \
            self.__a[2] * sin(theta[0]) * cos(theta[1]) * sin(theta[2])
        return Y

    def __getZ(self, theta):
        Z = self.__d[0] + self.__a[1] * cos(theta[1]) + self.__a[2] * -sin(theta[1]) * sin(theta[2]) + self.__a[
            2] * cos(theta[2]) * cos(theta[1])
        return Z

    def getXYZ(self, theta):
        self.__xyz = [self.__getX(theta), self.__getY(theta), self.__getZ(theta)]
        return self.__xyz
