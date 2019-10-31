
def isPrime(number):
    for i in range(2, number):
        if number % i == 0:
            return False
    return True


# 2, 3, 5, 7, 11, .. 
def process_item(x):

    x_int = int(x)
    if x_int <= 1:
        return 2

    found = False
    least_prime = x_int

    while found == False:
        least_prime = least_prime + 1

        if isPrime(least_prime):
            found = True
   
    return least_prime
