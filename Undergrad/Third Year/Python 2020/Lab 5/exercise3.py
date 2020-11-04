# Using functions, anonymous functions, list comprehensions
# and filter, implement three methods to generate a list
# will all the vowels in a given string.

# function
def method1(string):
    vowels = ["a", "e", "i", "o", "u"]
    result = []
    for character in string:
        if character.lower() in vowels:
            result.append(character)

    return result
print(method1("Programming in Python is fun"))


# anonymous function
vowels = ["a", "e", "i", "o", "u"]
method2 = lambda string: [character for character in string if character in vowels]
print(method2("Programming in Python is fun"))


# list comprehensions
string = "Programming in Python is fun"
method3 = [character for character in string if character in vowels]
print(method3)


# filter
def isVowel(character):
    vowels = ["a", "e", "i", "o", "u"]
    if character in vowels:
        return True
    return False

string = "Programming in Python is fun"
method4 = filter(isVowel, string)
print(list(method4))