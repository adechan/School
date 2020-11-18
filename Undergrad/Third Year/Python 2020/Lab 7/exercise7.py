# Write a script to simulate loto 6/49 draw (numbers extraction).
# The output should be a list of six numbers between 1 and 49 representing the winning combination.

import random

def function7():
    winning_combination = []

    for i in range (0, 6):
        x = random.randint(1, 49)
        winning_combination.append(x)

    return winning_combination


print(function7())