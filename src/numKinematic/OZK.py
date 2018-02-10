
from math import *

class InverseKinematic():
    def __init__(self, __a, __d):
        self.__a = __a
        self.__d = __d
        self.__q = [0, 0, 0]

    def getAngle1(self, X03, Y03, Z03):
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

    def __cosAngle(self, A, B, C):
        cAngle = (B * B + C * C - A * A) / (2 * B * C)
        return cAngle

    def __sinAngle(self, cAngle):
        sAngle = sqrt(1 - cAngle * cAngle)
        return sAngle

    def getAngle(self, x, y, z):
        a = 0.055
        g = sqrt(x * x + y * y) - a
        d = 0.17
        Angle = [0, 0, 0]
        Angle[0] = atan2(y, x)
        Long = [0.15, 0.14, 0]
        s = [g, z - d]
        Long[2] = sqrt(s[0] * s[0] + s[1] * s[1])
        if Long[0] + Long[1] > Long[2]:
            cosAngles = [0, 0]
            sinAngles = [0, 0]
            cosAngles[0] = self.__cosAngle(Long[0], Long[1], Long[2])
            cosAngles[1] = self.__cosAngle(Long[2], Long[0], Long[1])
            sinAngles[0] = self.__sinAngle(cosAngles[0])
            sinAngles[1] = self.__sinAngle(cosAngles[1])
            Angle[2] = (pi - atan2(sinAngles[1], cosAngles[1]))*(-1)
            Angle[1] = (pi / 2 - atan2(s[1], s[0]) - atan2(sinAngles[0], cosAngles[0])) * (-1)
        return Angle