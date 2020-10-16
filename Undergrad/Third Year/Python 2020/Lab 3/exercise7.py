# Write a function that receives a variable number of sets and
# returns a dictionary with the following operations from all
# sets two by two: reunion, intersection, a-b, b-a.
# The key will have the following form: "a op b", where a and b
# are two sets, and op is the applied operator: |, &, -.

def getOperation(setA, setB, operation):
    if operation == "|":
        return setA | setB  # union
    elif operation == "&":
        return setA & setB  # intersection
    elif operation == "-":
        return setA - setB  # difference


def function7(*sets):

    setOperations = dict()

    for i in range(0, len(sets), 2):
        setA = sets[i]
        setB = sets[i + 1]

        operations = ["|", "&", "-"]
        for operation in operations:
            setOperations[str(setA) + " " + operation + " " + str(setB)] = getOperation(setA, setB, operation)
            setOperations[str(setB) + " " + "-" + " " + str(setA)] = getOperation(setB, setA, "-")
    return setOperations

print(function7({1, 2}, {2, 3}, {3, 4}, {4, 5}))
