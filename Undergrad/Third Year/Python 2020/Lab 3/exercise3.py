# Compare two dictionaries without using the operator "==" and return a list
# of differences as follows: (Attention, dictionaries must be recursively
# covered because they can contain other containers, such as dictionaries, lists, sets, etc.)

# need to fix it!

def compareDictionaries(dictA, dictB):
    if len(dictA) != len(dictB):
        return False

    count = 0
    for itemA in dictA.items():
        for itemB in dictB.items():
            if itemA[0] in dictB.keys():
                if itemA[1] == itemB[1]:
                    count += 1

            if itemA[0] not in dictB.keys():
                return False

    if count == len(dictA):
        return True


dictA = {"a": 1, "b": 3}
dictB = {"a": 1, "b": 3}
print(dictA == dictB)