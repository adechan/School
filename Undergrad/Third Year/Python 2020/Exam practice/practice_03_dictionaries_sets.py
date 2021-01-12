# Curs 3
# SET
# set: unique elements -- use set() or {}
# unordered collection so you CAN'T access its elements (x[1]..)
# also you can't add 2 sets

x = set()
# CREATE a set
x = {1, 2, 3}  # --> {1, 2, 3}
x = {1, 1, 2, 3}  # --> {1, 2, 3}
x = set((1, 2, 3, 2))  # --> {1, 2, 3}
x = set([1, 2, 3, 2])  # --> {1, 2, 3}
x = set("Hello")  # --> {"h", "e", "l", "o"}

x = {1, 2, 3}
# DELETE/ ADD element in set
x.add(4)  # --> {1, 2, 3, 4}
x.remove(4)  # --> {1, 2, 3}
x.discard(2)  # --> {1, 3}
# x.remove(2)  # --> ERROR
# x.discard(2)  # --> ERROR

# UPDATE set
x = {1, 2, 3}
x |= {3, 4, 5}  # --> {1, 2, 3, 4, 5}
x.update({5, 6}, {7, 8})  # --> {1, 2, 3, 4, 5, 6, 7, 8}

# union, intersection, difference can have multiple parameters
# UNION: all elements |
x = {1, 2, 3}
y = {3, 4, 5}
t = {2, 4, 6}
z = x | y | t  # --> {1, 2, 3, 4, 5, 6}
s = {7, 8}
w = x.union(s)  # --> {1, 2, 3, 7, 8}

# INTERSECTION: common elements &
x = {1, 2, 3, 4}
y = {3, 4, 5}
t = {2, 4, 6}
z = x & y & t  # --> {4}
w = x.intersection(y)  # --> {3, 4}

# DIFFERENCE -
x = {1, 2, 3, 4}
y = {2, 3, 4, 5}
z = x - y  # --> {1}
w = y.difference(x)  # --> {5}

# can't have multiple parameters
# SYMMETRIC DIFFERENCE a - b, b - a ^
x = {1, 2, 3, 5}
y = {2, 3, 4}
z = x ^ y  # --> {1, 5, 4}
z = x.symmetric_difference(y)  # --> {1, 5, 4}

# isdisjoint: a set has no common elements with another one
# issubset or <=: a set is included in another one
# issuperset or >=: a set is included in another one
# x.isdisjoint(y): x has no common elements with y?
# x.issubset(y): x is subset of y?
# x.superset(y): x is superset of y?

x = {"A", "B", 1, 2, 3}  # --> {1, 2, 3, "A", "B"}
print(x.pop())  # --> "A" or "1"

# FROZENSET = SET but you CAN'T modify it
x = frozenset({1, 2, 3})
# x.add(10)  # --> ERROR

# DICTIONARY
# CREATE dictionary {"A": 1, "B": 2}
x = dict()
x = {"A": 1, "B": 2}
x = dict(A = 1, B = 2)
x = dict({"A": 1, "B": 2})
x = dict([("A", 1), ("B", 2)])
x = dict((("A", 1), ("B", 2)))
x = dict(zip(["A", "B"], [1, 2]))

# check if a key exists in dictionary: key in dictionary
# len(dictionary) = how many keys are in dictionary

# DEFAULT: add values to dictionary
x = {"A": 1, "B": 2}
y = x.setdefault("C", 3)  # --> {"A": 1, "B": 2, "C": 3}, y = 3
y = x.setdefault("D")  # --> {"A": 1, "B": 2, "C": 3, "D": None}, y = None
y = x.setdefault("A")  # -> {"A": 1, "B": 2, "C": 3, "D": None}, y = 1
y = x.setdefault("B", 20)  # --> {"A": 1, "B": 2, "C": 3, "D": None}, y= 2

# UPDATE" the values of keys
x = {"A": 1, "B": 2}
x.update({"A": 10})  # --> {"A": 10, "B": 2}
x.update({"C": 20})  # --> {"A": 10, "B": 2, "C": 20}
x.update(D = 3)  # --> {"A": 10, "B": 2, "C": 20, "D": 3}

# COPY dictionary: dict1.copy()
x = dict.fromkeys(["A", "B"], [1, 2])  # --> {'A': [1, 2], 'B': [1, 2]}
y = x.copy()  # --> y = {'A': [1, 2], 'B': [1, 2]}
y["C"] = 3  # --> y = {'A': [1, 2], 'B': [1, 2], 'C': 3}, x = {'A': [1, 2], 'B': [1, 2]}

# GET elements
x = {"A": 1, "B": 2}
y = x.get("A")  # --> y = 1
y = x.get("C")  # --> y = None
y = x.get("C", 3)  # --> y = 3

# EXTRACT elements
x = {"A": 1, "B": 2}
y = x.pop("A")  # --> y = 1, x = {"B": 2}
y = x.pop("C", 123)  # --> y = 123, x = {"B": 2} (works because it has default value)
# y = x.pop("D")  # --> ERROR

x = {"A": 2}
x["A"] = 3  # --> x = {"A": 3}

x = {i % 3: i for i in range(1, 9)}  # {0: 6, 1: 7, 2: 8}

# def name(**vars):
#     for key in vars:
#       if vars[key]...
# or
#     for key, value in vars.items():
#       if value = ...
# name(name1 = 10, name2 = 20)  --> {"name1": 10, "name2": 20}

x = {"A": 10, "B": 20}
for a in enumerate(x):
    print(a)  # --> (0, "A") (1, "B")
