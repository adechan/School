# Write a function that receives a variable number of positional
# arguments and a variable number of keyword arguments adn
# will return the number of positional arguments whose values
# can be found among keyword arguments values.

def function9(*posArguments, **keyArgs):
    count = 0

    for arg in posArguments:
        if arg in keyArgs.values():
            count = count + 1

    return count

print(function9(1, 2, 3, 4, x = 1, y = 2, z = 3, w = 5))
