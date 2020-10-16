# Write a function that receives as parameters two lists a and b and returns
# a set of sets containing: (a intersected with b, a reunited with b, a - b, b - a)

def setOperations(listA, listB):
    intersection = set(listA).intersection(set(listB))
    union = set(listA).union(set(listB))
    a_b = set(listA).difference(set(listB))
    b_a = set(listB).difference(set(listA))
    return (intersection, union, a_b, b_a)

listA = [1, 2, 3, 4]
listB = [3, 4, 5, 6]
print(setOperations(listA, listB))