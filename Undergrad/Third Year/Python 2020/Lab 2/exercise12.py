# Write a function that will receive a list of words
# as parameter and will return a list of lists of words,
# grouped by rhyme. Two words rhyme if both of them end
# with the same 2 letters.


def groupByRhyme(words):

    lastLetters = dict()

    for word in words:
        if word[len(word) - 2 : len(word) + 1] not in lastLetters.keys():
            lastLetters[word[len(word) - 2 : len(word) + 1]] = [word]
        else:
            lastLetters[word[len(word) - 2 : len(word) + 1]].append(word)

    group = []
    for key in lastLetters:
        group.append(lastLetters.get(key))

    return group


print(groupByRhyme(['ana', 'banana', 'carte', 'arme', 'parte']))