# Curs 2
# mutable: list, dictionary
# immutable: string, tuple (ex. s[0] = 't' not possible)

# list and tuples
print([1, 2] * 2)  # --> [1, 2, 1, 2]
print((1, 2) * 2)  # --> (1, 2, 1, 2)
print(1, 2 * 2)  # --> (1, 4)
print((1) * 2)  # --> int: 1 * 2
print((1, ) * 2)  # --> tuple (1, 1) !has comma

print(('A', 'B') + ('1', '2'))  # --> ('A', 'B', '1', '2')
print(['A', 'B'] + ['1', '2'])  # --> ['A', 'B', '1, '2']
# ('A', 'B') + ['1', '2'] --> ERROR

# lists methods
x = [1, 2, 3]
x.append(4)  # --> [1, 2, 3, 4]
x.append([4, 5])  # --> [1, 2, 3, 4, [4, 5]]
x += [8, 9]  # --> [1, 2, 3, 4, [4, 5], 8, 9]
x.extend([6, 7])  # --> [1, 2, 3, 4, [4, 5], 8, 9, 6, 7]
x.insert(1, "One")  # --> [1, 'One', 2, 3, 4, [4, 5], 8, 9, 6, 7]

x = [1, 2, 3, 4, 5]
x[0] = ["A", "B"]  # --> [["A", "B"], 2, 3, 4, 5]
x[2:] = ["a", "b"]  # --> [["A", "B"], 2, "a", "b"]
x[:3] = ["c", "d"]  # --> ["c", "d", "b"]
x[1:3] = ["One"]  # --> ["c", "One"]
x[0:2] = "ab"  # --> ["a", "b"]

x = [1, 2, 3, 4, 5]
del x[2]  # --> [1, 2, 4, 5]
x.remove(1)  # --> [2, 4, 5]
y = x.pop(2)  # --> x = [2, 4], y = 5

# HOW TO COPY LISTS:
# = doesn't make a copy, but only a reference of a list
x = [1, 2, 3]
y = x  # --> [1, 2, 3]
y.append(10)  # --> y = [1, 2, 3, 10], x = [1, 2, 3, 10]

# use list(x), x.copy(), x[:]W
x = [1, 2, 3]
y = list(x)
y.append(10)  # --> y = [1, 2, 3, 10], x = [1, 2, 3]

x = [1, 2, 3, 2, 4, 5, 2]
print(x.count(2))  # --> 3
print(x.count(10))  # --> 0

# SORT LISTS
x = [2, 1, 4, 3, 5]
x.sort()  # --> x = [1, 2, 3, 4, 5]
x.sort(reverse=True)  # --> x = [5, 4, 3, 2, 1]
x.sort(key = lambda i: i % 3)  # --> i % 3: [2, 1, 1, 0, 2] x = [3, 1, 4, 2, 5]
x.sort(key = lambda i: i % 3, reverse=True)  # --> [2, 5, 1, 4, 3]

x = [2, 1, 4, 3, 5]
y = sorted(x)  # --> y = [1, 2, 3, 4, 5]
y = sorted(x, reverse=True)  # --> y = [5, 4, 3, 2, 1]
y = sorted(x, key=lambda i: i % 3)  # --> i % 3 = [2, 1, 1, 0, 2], y = [3, 1, 4, 2, 5]
y = sorted(x, key=lambda i: i % 3, reverse=True)  # --> [2, 5, 1, 4, 3]

# MAP: creates a generator using lambda and a list
x = [1, 2, 3, 4, 5]
y = list(map(lambda el: el * el, x))  # --> y = [1, 4, 9, 16, 25]

x = [1, 2, 3]
y = [4, 5, 6]
z = list(map(lambda el1, el2: el1 + el2, x, y))  # --> y = [5, 7, 9]

# FILTER: creates a generator using lambda and a list
x = [1, 2, 3, 4, 5]
y = list(filter(lambda el: el % 2, x))  # --> y = [1, 3, 5]
y = list(filter(lambda el: el % 2 == 0, x))  # --> y = [2, 4]

# MAX/MIN: find biggest/ smallest
x = [1, 2, 3, 4, 5]
y = max(x)  # --> 5
y = max(1, 3, 2, 5, 7)  # --> y = 7
y = max(x, key=lambda i: i % 3)  # --> i % 3 = [1, 2, 0, 1, 2], y = 2

# ZIP
x = [1, 2, 3]
y = [10, 20, 30]
z = list(zip(x, y))  # --> z = [(1, 10), (2, 20), (3, 30)]

# UNZIP
z = [(1, 10), (2, 20), (3, 30)]
x, y = zip(*z)  # --> x = [1, 2, 3], y = [10, 20, 30]
