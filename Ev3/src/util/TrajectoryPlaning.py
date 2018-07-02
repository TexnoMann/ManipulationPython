class TrajectoryPlaning():
    def __init__(self, __filename):
        self.__file = open(__filename)
        s = self.__getNextCoords()
        self.startCoords = tuple([s[0:3], s[3:]])

    def __getNextCoords(self):
        part = self.__file.readline()
        if part == '':
            return None
        else:
            return tuple(map(float, part.split()))

    def readTrajectory(self):
        trajectory=[]
        while True:
            currentCoords = self.__getNextCoords()
            if currentCoords is None:
                break
            currentPoint = currentCoords[0:3]
            currentSpeed = currentCoords[3:]
            trajectory.append((currentPoint, currentSpeed))
        return tuple(trajectory)