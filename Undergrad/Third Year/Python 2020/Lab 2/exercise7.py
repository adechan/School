# . Write a function that receives as parameter a list of
# numbers (integers) and will return a tuple with 2 elements.
# The first element of the tuple will be the number of palindrome
# numbers found in the list and the second element will be the
# greatest palindrome number.

# input: list of numbers
# returns: tuple with 2 elements
# (number_of_palindromes_found, greatest_palindrome_found)

def isPalindrome(number):
    if number[:] == number[::-1]:
        return True
    return False

def palindromes(numbers):
    palindromesFound = []
    for number in numbers:
        if isPalindrome(str(number)):
            palindromesFound.append(number)

    biggest = max(palindromesFound)
    return (len(palindromesFound), biggest)


numbers = [11, 12, 13, 14, 15, 1, 2, 5, 22]
print(palindromes(numbers))