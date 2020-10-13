# Write a function that receives a number x, default
# value equal to 1, a list of strings, and a boolean
# flag set to True. For each string, generate a list
# containing the characters that have the ASCII
# divisible by x if the flag is set to True, otherwise
# it should contain characters that have the non-xvid ASCII code.

# for each string -> list containing characters that have ASCII divisible by x -> if flag is True
# flag = False: list with characters that dont have ASCII divisible by x

def isDivisible(number, x):
    if number % x == 0:
        return True
    return False

def function8(strings, flag = True, x = 1):

    result = []
    for string in strings:
        characters = []
        for character in string:
            if flag: ## flag == True
                if isDivisible(ord(character), x):
                    characters.append(character)
            else:
                if not isDivisible(ord(character), x):
                    characters.append(character)
        result.append(characters)

    return tuple(result)


strings = ["test", "hello", "lab002"]
print(function8(strings, flag = False, x = 2))