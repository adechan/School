# Write a function that extract a number from a text (for example if
# the text is "An apple is 123 USD", this function will return 123,
# or if the text is "abc123abc" the function will extract 123).
# The function will extract only the first number that is found.

def extractNumber(string):
    number = ""
    for index in range (0, len(string)):
        if string[index].isdigit():
            number += string[index]
            if string[index + 1].isdigit() == False:
                break

    return number


print(extractNumber("abc123abc"))