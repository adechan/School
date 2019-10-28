operators = {
    "+": lambda a, b: a + b,     
    "*": lambda a, b: a * b,
    "/": lambda a, b: a / b,
    "%": lambda a, b: a % b
}

# Question 1
def q1(namesList):
    return namesList.sort(key = lambda list : list[1])

# Question 2
def q2(namesList, firstName):

    return bool(firstName in map(lambda list : list[1], namesList))

# Question 3
def q3(op, a, b):
    return operators[op](a, b)

list = [("Kitty", "Andreea"), ("Meow", "Jo"), ("Ho", "Cat")]

print(list);
q1(list);
print(list);

print(q2(list, "John"))

x = 3
print(q3("+", x, 3));

