# Write a function called print_arguments with one parameter named function.
# The function will return one new function which prints the arguments
# and the keyword arguments received and will return the output of the
# function receives as a parameter.

def multiply_by_two(x):
    return x * 2

def add_numbers(a, b):
    return a + b

def print_arguments(function):
    def fn(*args, **kwargs):
        print(f'Arguments are {args}, {kwargs}')
        return function(*args)
    return fn


augmented_multiply_by_two = print_arguments(multiply_by_two)
x = augmented_multiply_by_two(10)
print(x)

augmented_add_numbers = print_arguments(add_numbers)
x = augmented_add_numbers(3, 4)
print(x)