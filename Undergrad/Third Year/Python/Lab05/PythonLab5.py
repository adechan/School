
import utils
import app

# Ex1.1 
n = input("Enter a value: " )
print("Next prime number is: ", utils.process_item(n))

# Ex1.2
# app.infinite_loop()

# Ex2
def sum(*x):
    sum = 0
    for i in x:
        sum += i
    return sum


def functionArgs(* args):
    sum = 0
    for i in args:
        sum += i
    return sum

print("Sum is:", functionArgs(1, 2, 3))

def anonymousArgs():
    return lambda *args: sum(*args)

print("Sum is:", anonymousArgs()(1, 2, 3))

# Ex3: generate a list with all the vowels in a given string
def functionVowels(string):
    vowels = "aeiouAEIOU"
    list_vowels = []

    for character in string:
        for vowel in vowels:
            if character == vowel:
                list_vowels.append(character)
    return list_vowels

print(functionVowels("AnaAreMere"))

def anonymousVowels():
    vowels = "aeiouAEIOU"
    return lambda string: [character for character in string if character in vowels]

print(anonymousVowels()("AnaAreMere"))

def listComprehesionsVowels(string):
    vowels = "aeiouAEIOU"
    return [character for character in string if character in vowels]

print(listComprehesionsVowels("AnaAreMere"))

# Ex4: list containing only the arguments which are dictionaries, containing 
# minimum 2 keys and at least one string key with minimum 3 characters