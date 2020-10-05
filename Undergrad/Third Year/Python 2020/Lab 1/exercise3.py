# Write a script that receives two strings and prints the number of occurrences
# of the first string in the second.

def occurencesFirstInSecond(stringA, stringB):
    length = len(stringA)
    count = 0

    for index in range(0, len(stringB)):
        if stringB[index : length + index] == stringA:
            count = count + 1
    return count

print(occurencesFirstInSecond("abc", "abcabcd"))