from ev3dev.ev3 import *

from time import *

i = 0
lcd = Screen()
while i < 20:
    lcd.clear()
    lcd.draw.text((10, 10), "sdfsdsd")
    lcd.update()
    sleep(1)
    i+=1
