# Write two functions to check if a number is prime, and check which
# of them is more time-efficient.

import time
import math


def isPrime1(number):
    count = 0
    for i in range(1, number + 1):
        if number % i == 0:
            count += 1

    if count == 2:
        return True
    return False

def isPrime2(number):
    isPrime = True
    if number == 0 | number == 1:
        return False
    for i in range(2, number // 2 + 1):
        if number % i == 0:
            isPrime = False
            break
    return isPrime


start = time.localtime().tm_sec
print(isPrime1(13332345))
end = time.localtime().tm_sec
print("First function seconds: ", end - start)

start = time.localtime().tm_sec
print(isPrime2(13332345))
end = time.localtime().tm_sec
print("Second function seconds: ", end - start)