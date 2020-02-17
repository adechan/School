# n-th fibonacci number
def fibo(n):
    if n <= 1: 
        return n
    return fibo(n - 1) + fibo(n - 2)

#print(fibo(0))

# prime number
def is_prime(number):
    if number == 1:
        return False

    for i in range(2, number):
        if number % i == 0:
            return False
    return True

def is_fibo(number):
    if number 

#print(is_prime(2))

# return list of numbers sorted in ascending order 
def custom_filter(my_list):
    new_list = []

    for number in my_list:
        if fibo(number) and is_prime(number):
            new_list.append(number)
    new_list.sort()
    return new_list

list = [29, 13, 5, 18, 21, 2, 9]
print(custom_filter(list))


