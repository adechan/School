# b) Write a module named app.py. When this module is run,
# it will run in an infinite loop, waiting for inputs
# from the user. The program will convert the input to a
# number and process it using the function process_item
# implented in utils.py. You will have to import this
# function in your module. The program stops when the
# user enters the message "q".

import utils

condition = True
inputs = []
primes = []
ints = []
while condition is True:
    inp = input()
    if inp == "q":
        break
    inputs.append(inp)

for element in inputs:
    try:
        ints.append(int(element))
    except ValueError:
        pass

for element in ints:
    primes.append(utils.process_item(element))

print(primes)

