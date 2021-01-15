# Curs 9

# self = this
# if you reference a variable that belongs to a class within the class => use self
# constructor: __init__ (must have self)
# function in class: must have self
# if the function doesn't have self => STATIC function for that class

# class = like a dictionary

# class Point has 2 members: x, y
class Point:
    def __init__(self):
        self.x = 0
        self.y = 0

    # method
    def Print(self):
        print(self.x, self.y)

    # static method
    def StaticPrint():
        print("I am a static function")

    def Test(self, value):
        return value

p = Point()
p.Print()  # --> x = 0, y = 0
p.z = 10
print(p.z)  # --> z = 10
# delete a member of a class instance: del
del p.z
# print(p.z)  # --> run time ERROR
Point.StaticPrint()  # --> I am a static function
# Point.print()  # --> ERROR: it has self (so it needs an object instance)
print(p.Test(5))
print("=================")

# you can define data member inside in the class,
# but not mutable objects
# mutable objects must be used in constructor

# bad
class Point:
    numbers = [1, 2, 3]

    def AddNumber(self, n):
        self.numbers += [n]

p1 = Point()
p2 = Point()
p1.AddNumber(4)
p2.AddNumber(5)
print(p1.numbers)  # --> p1: [1, 2, 3, 4, 5]  MUTABLE OBJECT
print(p2.numbers)  # --> p2: [1, 2, 3, 4, 5]  MUTABLE OBJECT

# good
class Point:
    def __init__(self):
        self.numbers = [1, 2, 3]

    def AddNumber(self, n):
        self.numbers += [n]

p1 = Point()
p2 = Point()
p1.AddNumber(4)
p2.AddNumber(5)
print(p1.numbers)  # --> p1: [1, 2, 3, 4]
print(p2.numbers)  # --> p2: [1, 2, 3, 5]
print("=================")

# class like a dictionary:
# method overloading is NOT possible (you cant have multiple functions with same key
# in dictionary), but you can create one method with a lot of parameters with
# default values

# no private/ protected attributes for data members

# implicit polymorphism (functions with same name but different parameters)
# you can use 2 different class types in the same way (we call functions without
# being concerned about which class type each object is)
# overriding: re-implement the method in the child class

class MyClass:
    x = 10
    y = 20

    def Test(self, value):
        return (self.x + self.y) / 2 == value

    def MyFunction(self, v1, v2):
        return str(v1 + v2) + " - " + str(self.x) + ", " + str(self.y)

m = MyClass()
print(m.Test(15))  # --> True; 10+20 / 2 = True
m.Test = m.MyFunction  # or MyClass().MyFunction // m.Test = refers to Test method
print(m.Test(1, 2))  # --> 3 - 10,20
print("=================")

m1 = MyClass()
m2 = MyClass()
m2.x = 100
print(m1.x, m2.x)  # --> m1.x = 10, m2.x = 100
m1.Test = m2.MyFunction
print(m1.MyFunction(1, 2))  # --> 3 - 10, 20
print(m1.Test(1, 2))  # --> 3 - 100, 20 (refers to m2.MyFunction)
print("=================")


class MyClass:
    x = 10
    y = 20
    def Test(self, value):
        return (self.x + self.y) / 2 == value

class AnotherClass:
    def MyFunction(self, v1, v2):
        return str(v1 + v2) + " - " + str(self.x) + ", " + str(self.y)

m = MyClass()
a = AnotherClass()
a.x = 30
a.y = 40
m.Test = a.MyFunction
print(m.Test(1, 2))  # --> 3 - 30, 40
print("=================")

class MyClass:
    x = 10
    y = 20

    def Test(self, value):
        return (self.x + self.y) / 2 == value

def MyFunction(v1, v2):
    return str(v1 + v2)

m = MyClass()
m.Test = MyFunction
print(m.Test(1, 2))  # --> 3
print("=================")


