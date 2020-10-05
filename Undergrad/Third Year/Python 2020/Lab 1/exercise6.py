# Write a function that validates if a number is a palindrome.

def isPalindrome(number):
    stringNumber = str(number)
    if stringNumber[0:] == stringNumber[::-1]:
        return True
    else:
        return False

print(isPalindrome(71))