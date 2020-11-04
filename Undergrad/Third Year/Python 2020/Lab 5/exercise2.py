# Create a function and an anonymous function that receive
# a variable number of arguments. Both will return the sum
# of the values of the keyword arguments.

def sumF1(*args, **kargs):
    sum = 0
    for argument in kargs:
        sum += kargs[argument]

    return sum


print(sumF1(1, a = 2, b = 3))

sumF2 = lambda *args, **kargs: sum(**kargs)
print(sumF2(1, a = 2, b = 3))