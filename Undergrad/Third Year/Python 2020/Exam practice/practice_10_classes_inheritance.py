# Curs 10

# INHERITANCE
class Base:  # has only x
    x = 10

class Derived(Base):  # has both x and y
    y = 20
d = Derived()
print(d.x)  # --> 10
print(d.y)  # --> 20
print("=================")

class Base:
    def __init__(self):
        self.x = 10

class Derived(Base):
    def __init__(self):
        self.y = 20
d = Derived()
# print(d.x)  # --> ERROR: its not called in Derived (so it doesnt have x)
print(d.y)  # --> 20
print("=================")

class Base:  # overwritten by Derived
    def __init__(self):
        self.x = 10

class Derived(Base):
    def __init__(self):
        Base.__init__(self)  # --> calls the constructor for Base
        self.y = 20
d = Derived()
print(d.x)
print(d.y)
print("=================")

class BaseA:
    def MyFunction(self):
        print("Base A")
class BaseB:
    def MyFunction(self):
        print("Base B")
class Derived(BaseA, BaseB):  # derives from right most class to the left most class
    pass

d = Derived()
d.MyFunction()  # --> "Base A"
print("=================")

class Test1:
    x = 10

class Test2:
    x = 10

    def __str__(self):  # tells how to handle string representation for the object
        return "Test2 with x = " + str(self.x)

t1 = Test1()
t2 = Test2()
print(t1, " : ", str(t1))  # --> <__main__.Test1 object at 0x000002770B316430>  :  <__main__.Test1 object at 0x000002770B316430>
print(t2, " : ", str(t2))  # --> Test2 with x = 10  :  Test2 with x = 10
print("=================")

# the methods starting with __X__ describe how the object (class instance) acts
# for printing the object you need to implement __str__

class Test1:
    def __init__(self):
        print("Test1 class")

class Test2(Test1):
    def __init__(self):
        Test1.__init__(self)  # needs to call the main constructor as well
        print("Test2 class")

d = Test2()
print(d)