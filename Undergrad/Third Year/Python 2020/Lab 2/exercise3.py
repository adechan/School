# Write a function that receives as parameters two lists
# a and b and returns: (a intersected with b,
# a reunited with b, a - b, b - a)

def operations(listA, listB):
    intersected = []
    for elementA in listA:
        for elementB in listB:
            if elementA == elementB:
                intersected.append(elementA)

    reunion = list(listA)
    for elementB in listB:
        if elementB not in reunion:
            reunion.append(elementB)

    a_b = list(listA)
    for elementB in listB:
        if elementB in a_b:
            a_b.remove(elementB)

    b_a = list(listB)
    for elementA in listA:
        if elementA in b_a:
            b_a.remove(elementA)

    return (intersected, reunion, a_b, b_a)


listA = [2, 3, 4, 5, 6]
listB = [4, 5, 6, 7, 8, 9]
print(operations(listA, listB))