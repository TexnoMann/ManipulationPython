from math import *
def  cosAngle(A,B,C):
    cAngle =( B*B + C*C - A*A)/(2*B*C)
    return cAngle
def sinAngle(cAngle):
    sAngle = sqrt(1-cAngle*cAngle)
    return sAngle


def main():
    x = -0.03
    y = -0.03
    z = 0.11
    a = 0.055
    g = sqrt(x*x + y*y) - a
    d =0.17
    Angle = [0,0,0]
    Angle[0] = atan2(y,x)
    Long = [0.15,0.14,0]
    s = [g,z-d]
    Long[2] = sqrt(s[0]*s[0] + s[1]*s[1])
    if Long[0]+Long[1] > Long[2]:
        cosAngles = [0,0]
        sinAngles = [0,0]
        cosAngles[0] = cosAngle(Long[0],Long[1],Long[2])
        cosAngles[1] = cosAngle(Long[2],Long[0],Long[1])
        sinAngles[0] = sinAngle(cosAngles[0])
        sinAngles[1] = sinAngle(cosAngles[1])
        Angle[2] = pi - atan2(sinAngles[1],cosAngles[1])
        Angle[1] = pi/2 - atan2(s[1],s[0]) - atan2(sinAngles[0],cosAngles[0])
    elif Long[0] + Long[1] < Long[2]:
        print('NOT ANGLE!')
    print(Angle[0]*180/pi,'  ', Angle[1]*180/pi,'  ',Angle[2]*180/pi)


if __name__ == '__main__':
    main()