from math import *

class InverseKinematic():
    def __init__(self,__a,__d):
        self.__a = __a
        self.__d = __d
        self.__q = [0, 0, 0]

    def getAngle(self, X03, Y03, Z03):
        self.__q[0] = atan2(Y03, X03)
        X13 = X03-self.__a[0]
        Y13 = Z03-self.__d[0]
        b = Y13
        c = X13
        cq = (pow(b, 2) + pow(c, 2) - pow(self.__a[1], 2) - pow(self.__a[2], 2)) / (2 * self.__a[1] * self.__a[2])
        self.__q[2] = atan2(sqrt(1-cq), cq)
        self.__q[1] = atan2(b, c)-atan2(sin(self.__q[2])*self.__a[2], self.__a[1]+self.__a[2]*cq)
        return self.__q

