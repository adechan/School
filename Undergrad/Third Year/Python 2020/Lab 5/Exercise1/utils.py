# a) Write a module named utils.py that contains one function
# called process_item. The function will have one parameter,
# x, and will return the least prime number greater than x.
# When run, the module will request an input from the user,
# convert it to a number and it will display the output of the
# process_item function.

def isPrime(x):
    divisors = 0
    for number in range(1, x + 1):
        if x % number == 0:
            divisors += 1

    if divisors == 2:
        return True
    return False

def process_item(x):

    number = int(x)

    prime = number + 1;
    while isPrime(prime) == False:
        prime += 1

    return prime
