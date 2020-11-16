# Write a program that will write the minutes passed from the start,
# every x seconds, where x is random chosen at each iteraton (from
# the inteval [a, b] , where a, b are arguments). The program will
# run infinitely.

import random
import time
import math

def function1(a, b):
    tobj = time.localtime()
    minutes = tobj.tm_min # minutes

    print("Time: ", time.strftime("%H:%M:%S", tobj))

    while True:
        x = random.randint(a, b)
        print("x: ", x)
        time.sleep(x)
        new_now = time.localtime()
        new_minutes = new_now.tm_min

        # print(minutes)
        # print(new_minutes)
        passed_minutes = minutes - new_minutes
        if (int(minutes) == 59 & int(new_minutes) == 0) | (int(minutes) == 0 & int(new_minutes) == 59):
            passed_minutes = 1.0

        print("Time: ", time.strftime("%H:%M:%S", new_now))
        print("Minutes passed: ", math.fabs(passed_minutes))


print(function1(1, 50))
