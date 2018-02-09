
from math import *

class InverseKinematic():
    def __init__(self, __a, __d):
        self.__a = __a
        self.__d = __d
        self.__q = [0, 0, 0]

    def getAngle(self, X03, Y03, Z03):
        self.__q[0] = atan2(Y03, X03)

        X01 = self.__a[0]*cos(self.__q[0])
        Z01 = self.__d[0]
        Y01 = self.__a[0]*sin(self.__q[0])
        X13 = X03-X01
        Y13 = Z03-Z01

        b2 = pow(X13, 2)
        c2 = pow(Y13, 2)
        b = X13
        c = Y13
        d2 = b2 + c2

        cq2 = (d2 - pow(self.__a[1], 2) - pow(self.__a[2], 2))/(2*self.__a[1]*self.__a[2])
        self.__q[2] = atan2(-sqrt(1-pow(cq2, 2)), cq2)
        print(self.__q[2])
        self.__q[1] = -atan2(c, b)+pi/2-atan2(self.__a[2]*sin(self.__q[2]), self.__a[1]+cos(self.__q[2]))
        print(self.__q[1])

        return self.__q
