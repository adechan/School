
import utils
import app

# Ex1.1 
n = input("Enter a value: " )
print("Next prime number is: ", utils.process_item(n))

# Ex1.2
# app.infinite_loop()

# Ex2
def sum(*x):
    sum = 0
    for i in x:
        sum += i
    return sum


def functionArgs(* args):
    sum = 0
    for i in args:
        sum += i
    return sum

print("Sum is:", functionArgs(1, 2, 3))

def anonymousArgs():
    return lambda *args: sum(*args)

print("Sum is:", anonymousArgs()(1, 2, 3))

# Ex3: generate a list with all the vowels in a given string
def functionVowels(string):
    vowels = "aeiouAEIOU"
    list_vowels = []

    for character in string:
        for vowel in vowels:
            if character == vowel:
                list_vowels.append(character)
    return list_vowels

print(functionVowels("AnaAreMere"))

def anonymousVowels():
    vowels = "aeiouAEIOU"
    return lambda string: [character for character in string if character in vowels]

print(anonymousVowels()("AnaAreMere"))

def listComprehesionsVowels(string):
    vowels = "aeiouAEIOU"
    return [character for character in string if character in vowels]

print(listComprehesionsVowels("AnaAreMere"))

# Ex4: list containing only the arguments which are dictionaries, containing 
# minimum 2 keys and at least one string key with minimum 3 characters

# minimum 2 keys, 1 key with 3 characters+
def prob4(* args):
    count_keys_characters = 0
    list_dictionaries = list();
    dictionary = dict()

    for arg in args:
        if type(arg) == dict:
            if len(arg) >= 2:
                for key, value in arg.items():
                    if len(key) >= 3:
                        count_keys_characters += 1

                for key, value in arg.items():
                    if count_keys_characters != 0:
                        list_dictionaries.append({key:value})

    return list_dictionaries


print(prob4(           
      {'abc' : 4, 'def' : 5}, 
      [1, 2, 3],
      {'1': 1, 'test': True},
      {'ab': 4, 'ac': 'abcde', 'fg': 'abc'}
      ))

# Ex5: f(list) : new list contining all numbers found in list
def numbersInList(list):
    new_list = []
    for i in list:
        if type(i) == int:
            new_list.append(i)
    return new_list

list = [1, "2", {"3": "a"} , {4, 5}, 5, 6, 3.0]
print(numbersInList(list))

# Ex6: 2 functions(2 lists of tuples), lists of same length
# 1f: will use the map function
# 2f: will use the zip function 
# will return a list of tuples (a, b, c) representing the lines determined by the points
def findLine(point1, point2):

   # (x1, y1), (x2, y2)
   # m = (y2 - y1) / (x2 - x1)
   # b = y2 - m x2 || b = y1 = m x1
   # equation: y = mx = b

    slope = (point2[1] - point1[1])/ (point2[0] - point1[0])
    b = point1[1] - slope * point1[0]

    point3 = (slope, -1, b)
    return point3

# zip
def linePoints(list1, list2):
    list_line = []
    for point1, point2 in zip (list1, list2):
        list_line = list_line + [findLine(point1, point2)]
    return list_line

list1 = [(1, 2), (3, 4)]
list2 = [(3, 4), (5, 6)]
print(linePoints(list1, list2))

# map
def linePoints2(list1, list2):
    # zip(list1, list2) returns 2 tuples
    return [x for x in map(lambda t : findLine(t[0], t[1]), zip(list1, list2))]

print(linePoints2(list1, list2))

# Ex7 