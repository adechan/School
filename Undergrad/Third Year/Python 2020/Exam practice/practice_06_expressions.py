# Curs 6
# regular expressions

# .: all characters except new line
# ^: start of string
# [^..]: not those characters inside
# $: end of string
# *: >= 0
# +: >= 1
# ?: 0/1
# {x}: matches x times
# {x,y}: matches between x and y times
# []: group
# |: or
# \d: 0-9
# \s: space, tab, newline
# \w: a-zA-Z0-9_
# \: escape

import re

# MATCH: find a match inside the string
# starts the matching from the beginning of the string
# stops once the matching ends
def ex1():
    r = re.compile("[0-9a-z]+")
    if r.match("123aazAZ"):  # --> "123aaz"
        print("Match")
ex1()

# SEARCH: check to see if it matches a part of the string
# stops after the first match
def ex2():
    r = re.compile("[a-zA-Z]*")
    result = r.search("A 323 BCD")  # if it can't make a match --> returns None --> False
    if result:  # --> "A"
        print(result.group(0))
ex2()

# *,+ GREEDY
# *?,+? NON-GREEDY
# GREEDY
def ex3():
    r = re.compile(".*(\\d+)")
    result = r.search("File size if 12345 bytes")
    if result:
        print("Group 0: " + result.group(0))  # --> "File size if 12345 bytes"
        print("Group 1: " + result.group(1))  # --> 5
ex3()

# NON-GREEDY
def ex4():
    r = re.compile(".*?(\\d+)")
    result = r.search("File size if 12345 bytes")
    if result:
        print("Group 0: " + result.group(0))  # --> "File size if 12345 bytes"
        print("Group 1: " + result.group(1))  # --> 12345
ex4()

def ex5():
    r = re.compile("(\\d+)[^\\d]*(\\d+)")  # starts with number - anything but not number - ends with number
    result = r.search("Price is 123 USD aprox 110 EUR")
    if result:
        print("Max group index: " + str(result.lastindex))
        print("Group 0: " + result.group(0))  # --> "123 USD aprox 110"
        print("Group 1: " + result.group(1))  # --> "123"
        print("Group 2: " + result.group(2))  # --> "110"
ex5()

def ex6():
    r = re.compile("((\\d+),(\\d+))[^\d]*(\\d+)")
    result = r.search("Color from pixel 20,30 is 123")
    if result:
        # group - from biggest () to smallest
        print("Group 0: " + result.group(0))  # --> "20,30 is 123"
        print("Group 1: " + result.group(1))  # --> "20,30"
        print("Group 2: " + result.group(2))  # --> "20"
        print("Group 3: " + result.group(3))  # --> "30"
        print("Group 4: " + result.group(4))  # --> "123"
ex6()

# FINDALL: find all substring that matches
def ex7():
    r = re.compile("\\d+")
    result = r.findall("Color from pixel 20,30 is 123")
    if result:
        print(result)  # --> ["20", "30", "123"]
ex7()

def ex8():
    r = re.compile("(\\d)(\\d+)")
    result = r.findall("Color from pixel 20,30 is 123")
    if result:
        # ()() -> tuples with 2 elements
        print(result)  # --> [("2", "0"), ("3", "0"), ("1", "23")]
ex8()

# SPLIT
def ex9():
    result = re.split("[aeiou]+", "Color from pixel 20,30 is 123")
    print(result)  # --> ["C", "l", "r fr", "m p", "x", "l 20,30 ", "s 123"]
ex9()

def ex10():
    result = re.split("\\d\\d", "Color from pixel 20,30 is 123")
    print(result)  # --> ["Color from pixel ", ",", " is ", "3"]

    result = re.split("[A-Z]+", "Colors")
    print(result)  # --> ["", "olors"]

    result = re.split("[a-z]+", "Colors")
    print(result)  # --> ["C", ""]

    result = re.split("[A-Z]*", "Colors")
    print(result)  # --> ["", "", "o", "l", "o", "r", "s", ""]

    result = re.split("[a-z]*", "Colors")
    print(result)  # --> ["", "C", "", ""]
ex10()

def ex11():
    # split is done after each group of matches
    # the group is also RETURNED!
    # and the remainder of the string is also returned
    # if it matches start of the string: "" as first element in list
    result = re.split("(\\d)(\\d)", "Color from pixel 20,30 is 123")
    print(result)  # --> ["Color from pixel ", "2", "0", ",", "3", "0", " is ", "1", "2", "3"]

    result = re.split("([a-z]+)", "Colors")
    print(result)  # --> ["C", "olors", ""]

    # "" -> capture ""
    # "C" -> capture "olors"
    # "" -> capture ""
    # "" end
    result = re.split("([a-z]*)", "Colors")
    print(result)  # --> ["", "", "C", "olors", "", "", ""]

    result = re.split("[a-z]*", "Colors")
    print(result)  # --> ["", "C", "", ""]

    result = re.split("([a-z]+)", "adeLica")
    print(result)  # --> ["", "ade", "L", "ica", ""]
ex11()

def ex12():
    result = re.split("\\d\\d+", "12345")
    print(result)  # --> ["", ""]

    result = re.split("(\\d\\d+)", "12345")
    print(result)  # --> ["", "12345", ""]

    result = re.split("\\d\\d*", "12345")
    print(result)  # --> ["", ""]

    result = re.split("(\\d\\d*)", "12345")
    print(result)  # --> ["", "12345", ""]
ex12()

def ex13():
    result = re.split("\\d", "12345")
    print(result)  # --> ["", "", "", "", "", ""]
ex13()

def ex14():
    result = re.split("(\\d)", "12345")
    print(result)  # --> ["", "1", "", "2", "", "3", "", "4", "", "5", ""]

    result = re.split("(\\d+)", "12345")
    print(result)  # --> ["", "12345", ""]

    result = re.split("(\\d*)", "12345")
    print(result)  # --> ["", "12345", "", "", ""]
ex14()

def ex15():
    result = re.split("(\\d\\d+)", "Color from pixel 20,30 is 123")
    print(result)  # --> ["Color from pixel ", "20", ",", "30", " is ", "123", ""]
ex15()

def ex16():
    s = "Today I'm having a python course"
    # split by upper case letters, spaces
    print(re.split("[^a-z']+", s))  # --> ["", "oday", "'m", "having", "a", "python", "course"]
    print(re.split("[^a-z']+", s, 2))   # --> ["", "oday", 'm having a python course]
    print(re.split("[^a-z']", s, flags=re.IGNORECASE))  # --> ["Today", "I'm", "having", "a", "python", "course"]
    print(re.split("[^a-z']", s, 2, flags=re.IGNORECASE)) # --> ["Today, "I'm", "having a python course"]
ex16()

# SUB: replace a matched string with another string