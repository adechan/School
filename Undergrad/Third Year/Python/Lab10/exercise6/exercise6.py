
# prime: 2, 3, 5, 7, 11, ... 
import time

def is_prime(n):
	if n == 2:
		return True

	for i in range(2, n):
		if n % i == 0:
			return False

	return True

time_1 = time.time()
print(is_prime(9))
time_2 = time.time()
result_function_1 = time_2 - time_1
print(result_function_1)

def is_prime2(n):
	if n == 2:
		return True
	for i in range(2, n//2):
		if n % i == 0:
			return False

	return True

time_1_2 = time.time()
print(is_prime2(11))
time_2_2 = time.time()
result_function_1_2 = time_2_2 - time_1_2
print(result_function_1_2)

if result_function_1 < result_function_1_2:
	print("Function one is better than function two")
else:
	print("Function two is better than function one")