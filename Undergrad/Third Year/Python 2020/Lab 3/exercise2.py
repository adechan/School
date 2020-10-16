# Write a function that receives a string as a parameter and returns
# a dictionary in which the keys are the characters in the
# character string and the values are the number of occurrences
# of that character in the given text.

def characterOccurrences(string):
    occurrences = dict()

    for character in string:
        if character not in occurrences:
            occurrences[character] = 1
        else:
            occurrences[character] += 1

    return occurrences

print(characterOccurrences("Ana has apples."))