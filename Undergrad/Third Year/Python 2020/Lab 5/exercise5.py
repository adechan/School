# Write a function with one parameter which represents a list.
# The function will return a new list containing all the numbers
# found in the given list.

def function5(list):
    numbers = []
    for element in list:
        if type(element) == int or type(element) == float:
            numbers.append(element)

    return numbers


print(function5([1, "2", {"3": "a"}, {4, 5}, 5, 6, 3.0]))