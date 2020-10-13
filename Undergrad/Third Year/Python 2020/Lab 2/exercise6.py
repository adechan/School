g  # Write a function that receives as a parameter a


# variable number of lists and a whole number x.
# Return a list containing the items that appear
# exactly x times in the incoming lists.

# input: any number of lists, x
# returns: list that contains the items that appear "x" times in the lists

def countItems(*lists, x):
    # treat args as a list
    # list of lists

    reunion = []
    for list in lists:
        for element in list:
            reunion.append(element)

    finalList = []
    for element in reunion:
        count = reunion.count(element)
        if count == x:
            finalList.append(element)

    noDuplicates = []
    for element in finalList:
        if element in noDuplicates:
            continue
        else:
            noDuplicates.append(element)

    return noDuplicates


list1 = [1, 2, 3, 2]
list2 = [2, 3, 4, 5, 1]
print(countItems(list1, list2, x=3))
