# Write a function that counts how many bits with value
# 1 a number has. For example for number 24, the binary format
# is 00011000, meaning 2 bits with value "1"

def toBinary(number):
    binary = ""
    while number != 0:
        rest = number % 2
        number = number // 2
        binary += str(rest)

    return binary[::-1] # reversed

# print(toBinary(24))

def count1s(number):
    count = 0
    binary = toBinary(number)

    for char in binary:
        if char == "1":
            count = count + 1

    return count

print(count1s(24))

