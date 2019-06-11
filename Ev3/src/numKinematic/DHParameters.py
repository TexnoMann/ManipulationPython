class DHParameters:
    def __init__(self, a, d, alpha, gripperLong):
        self.__gripperLong=gripperLong
        self.__a = a
        self.__d = d
        self.__a[-1] += gripperLong
        self.__alpha = alpha

    def getD(self):
        return self.__d

    def getA(self):
        return self.__a

    def getAlpha(self):
        return self.__alpha