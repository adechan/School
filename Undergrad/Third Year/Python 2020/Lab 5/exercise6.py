# Write a function that receives a list with integers as parameter
# that contains an equal number of even and odd numbers that are in
# no specific order. The function should return a list of pairs
# (tuples of 2 elements) of numbers (Xi, Yi) such that Xi is the
# i-th even number in the list and Yi is the i-th odd number.


def nTH(list, position, flag):
    count = 0
    if flag == "even":
        for element in list:
            if element % 2 == 0:
                count += 1

            if count == position + 1:
                return element

    elif flag == "odd":
        for element in list:
            if element % 2 != 0:
                count += 1

            if count == position + 1:
                return element

# print(nTH([1, 3, 5, 2, 8, 7, 4, 10, 9, 2], 2, "odd"))


def function6(list):
    result = []

    for index in range(0, int(len(list) / 2)):
        result.append((nTH(list, index, "even"), nTH(list, index, "odd")))

    return result


print(function6([1, 3, 5, 2, 8, 7, 4, 10, 9, 2]))