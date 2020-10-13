g# Write a function that receives a list of numbers and returns a
# list of the prime numbers found in it.
def isPrime(number):
    count = 0
    for index in range(1, number + 1):
        if number % index == 0:
            count += 1

    if count == 2:
        return True
    return False

# print(isPrime(9))

def primeNumbers(numbers):
    primes = []
    for number in numbers:
        if isPrime(number):
            primes.append(number)

    return primes


print(primeNumbers([1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11]))