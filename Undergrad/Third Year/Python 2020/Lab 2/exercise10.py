# Write a function that receives a variable number of lists
# and returns a list of tuples as follows: the first tuple
# contains the first items in the lists, the second element
# contains the items on the position 2 in the lists, etc.

def function10(*lists):
    result = []
    for i in range(0, len(lists)):
        sublist = []
        for j in range(0, len(lists[0])):
            sublist.append(lists[j][i])
        result.append(tuple(sublist))

    return result


print(function10([1, 2, 3], [5, 6, 7], ["a", "b", "c"]))
