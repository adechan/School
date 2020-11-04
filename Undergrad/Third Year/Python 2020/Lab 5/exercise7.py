# Write a function called process that receives a
# variable number of keyword arguments
# The function generates the first 1000 numbers of
# the Fibonacci sequence and then processes them in the following way:
# If the function receives a parameter called filters,
# this will be a list of predicates (function receiving
# an argument and returning True/False) and will retain
# from the generated numbers only those for which the predicates are True.
# If the function receives a parameter called limit,
# it will return only that amount of numbers from the sequence.
# If the function receives a parameter called offset, it
# will skip that number of entries from the beginning of the result list.

def fibonacci(firstNth):
    result = []
    result.append(0)
    result.append(1)

    for index in range(0, firstNth):
        result.append(result[index] + result[index + 1])

    return  result


def process(**kwargs):
    fib = fibonacci(1000)

    for arg in kwargs:
        if arg == "filters":
            for item in arg:
                pass

    return fib

def sum_digits(x):

    return sum(map(int, str(x)))


print(process(filters=[lambda item: item % 2 == 0, lambda item: item == 2 or 4 <= sum_digits(item) <= 20],))