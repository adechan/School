#  Write a function to return a list of the first n numbers in the
#  Fibonacci string.

def firstNFibonacci(n):
    fibonnaci = []
    fibonnaci.append(0)
    fibonnaci.append(1)
    for index in range(0, n - 2):
        fibonnaci.append((fibonnaci[index] + fibonnaci[index + 1]))
    return fibonnaci


print(firstNFibonacci(8))