from math import *

th0 = 30
th1 = 30
th2 = 30
a1 = 1
a2 = 1
a3 = 1
f = 30*pi/180

H03 = [[cos(th0) * cos(th1) * cos(th2) - cos(th0) * sin(th1) * sin(th2), -cos(th0) * cos(th1) * sin(th2) - cos(th0) * cos(th2) * sin(th1), sin(th0), a2 * cos(f) * cos(th0) + a3 * cos(th0) * cos(th1) + a3 * cos(th0) * cos(th1) * cos(th2) - a3 * cos(th0) * sin(th1) * sin(th2)], [cos(th1) * cos(th2) * sin(th0) - sin(th0) * sin(th1) * sin(th2), - cos(th1) * sin(th0) * sin(th2) - cos(th2) * sin(th0) * sin(th1), -cos(th0), a2 * cos(f) * sin(th0) + a3 * cos(th1) * sin(th0) + a3 * cos(th1) * cos(th2) * sin(th0) - a3 * sin(th0) * sin(th1) * sin(th2)], [cos(th1) * sin(th2) + cos(th2) * sin(th1), cos(th1) * cos(th2) - sin(th1) * sin(th2), 0, a1 + a2 * sin(f) + a3 * sin(th1) + a3 * cos(th1) * sin(th2) + a3 * cos(th2) * sin(th1)], [0, 0, 0, 1]]
