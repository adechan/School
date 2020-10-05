# Find The greatest common divisor of 2 or more numbers read from the console.

def gcd(a, b):
    while a % b > 0:
        r = a % b
        a = b
        b = r
    return b
# print(gcd(54, 12))

numbers = []
n = int(input("Number of elements: "))
for i in range(0, n):
    element = int(input())
    numbers.append(element)

# numbers = [54, 12, 36]
def gcd_multiple_numbers(numbers):
    final = 0

    if (len(numbers) < 2):
        return "You need to type at least 2 numbers"

    while len(numbers) >= 2:
        print("List: ", numbers)

        result = gcd(numbers[0], numbers[1]) # gcd between the first 2 numbers in list
        # remove the first 2 numbers in list
        numbers.pop(0)
        numbers.pop(0)

        # append the new value in the list
        numbers.insert(0, result)

        if len(numbers) < 2:
            final = numbers[0]
    return final


print(gcd_multiple_numbers(numbers))
