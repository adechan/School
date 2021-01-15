# Curs 1
print(10 / 3)  # --> 3.33.. (FLOAT)
print(10 // 3)  # --> 3 (INT)
print(10.0 // 3)  # --> 3.0 (FLOAT)
print(11.9 // 3)  # --> 3.0 (FLOAT)
print(int(11.9))  # --> 11

# bitwise operators
# depasiri
print(254 & 0xFF)  # --> 254 (fits in 256)
print(256 & 0xFF)  # --> 0
print(257 & 0xFF)  # --> 1 (because it doesn't fit in 256)

print(5 & 9)  # --> 0101 & 1001 = 0001 = 1
print(5 | 9)  # --> 0101 | 1001 = 1101 = 13
print(5 ^ 9)  # --> 0101 ^ 1001 = 1100 = 12
print(9 << 1)  # --> 1001 << 1 = 10010 = 18
print(9 << 2)  # --> 1001 << 2 = 100100 = 36
print(9 >> 1)  # --> 1001 >> 1 = 0100 = 4
print(9 >> 2)  # --> 1001 >> 2 = 0010 = 2

# formatted string literals
a = 3
print(f"A = {a}")  # --> A = 3
print(f"A = {a:5}")  # --> A =.....5  (has spaces in the left)

# string types
s = "PythonExam"  # begin:end:step
print(s[0])  # --> P
print(s[-1])  # --> m
print(s[-2])  # --> a

print(s[:3])  # --> Pyt
print(s[4:])  # --> onExam

print(s[3:5])  # --> ho
print(s[2:-4])  # --> thon
print(s[::-1])  # --> maxEnohtyP
print(s[1:7:2])  # --> yhn

s = "AB||CD||EF||GH"
print(s.split("||"))  # --> ["AB", "CD", "EF", "GH"]
print(s.split("||")[0])  # --> "AB"
print(s.split("||", 1))  # --> ["AB", "CD||EF||GH"]
print(s.split("||", 2))  # --> ["AB", "CD", "EF||GH"]
print(s.rsplit("||", 1))  # --> ["AB||CD||EF", "GH"]

print(chr(71))  # --> converts a number to a character
print(ord('a'))  # --> converts a character to number

# WHILE loop
# -> if there is "else" after while loop, the else loop always executes
# -> if there is "else" after while loop, but there is "break" inside while ->
# the else loop doesn't executes
# -> if there is "else" after while loop, but there is "continue" inside while ->
# the else loop executes

# FOR loop
# range (start, end, step)
# range(0, 3) -> [0, 3)
# range(0, 8, 3) -> [0, 3, 6]
# range(3) -> [0, 3)

# def name(x = 2, y, z = 3) --> ERROR: y must have default value as well


