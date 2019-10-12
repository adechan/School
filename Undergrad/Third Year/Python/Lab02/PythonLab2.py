# Ex1. 
# Sa se scrie o functie care sa returneze o lista cu primele
# n numere din sirul lui Fibonacci

def nNumbersFromFibonacci(n):

    listFibonacci = []

    if n == 1 :
        listFibonacci.append(1)

    if n == 2 : 
        listFibonacci.append(1)
        listFibonacci.append(1)
        listFibonacci.append(2)

    sumOfLastTwo = 0
    number1 = 0
    number2 = 1

    for index in range(0, n, 1):
        listFibonacci.append(number2)

        sumOfLastTwo = number1 + number2
        number1 = number2
        number2 = sumOfLastTwo

    

    return listFibonacci

print("First n Fibonacci numbers: ", nNumbersFromFibonacci(5))

# Ex2 
# prime = shouldnt be divisible by other numbers than 1 and itself
def primeNumber(number):
    for i in range(2, number, 1):
        if number % i == 0:
            return False
    return True

def primeNumbers(listNumbers):
    listPrimeNumbers = []

    for number in listNumbers:
        if primeNumber(number):
            listPrimeNumbers.append(number)
    return listPrimeNumbers

listNumber = [1, 2, 3, 5, 6, 15]
print("List of prime numbers: ", primeNumbers(listNumber))

# Ex3
def findLine(point1, point2):

   # (x1, y1), (x2, y2)
   # m = (y2 - y1) / (x2 - x1)
   # b = y2 - m x2 || b = y1 = m x1
   # equation: y = mx = b

    slope = (point2[1] - point1[1])/ (point2[0] - point1[0])
    b = point1[1] - slope * point1[0]

    point3 = (slope, -1, b)
    return point3

point1 = (1, 1)
point2 = (2, 3)
print("Points " + str(point1) + " " + str(point2) + " Line: ", findLine(point1, point2))


def findLines(listOfPoints):
    listOfLines = []

    for point1, point2 in zip(listOfPoints, listOfPoints[1:]):
         listOfLines.append(findLine(point1, point2))
    return listOfLines

listOfPoints = [(1, 1), (2, 3)]
print("Points " + str(listOfPoints[0]) + " " + str(listOfPoints[1]) + " Line: ", findLines(listOfPoints))

# Ex4
def operationReunion(list1, list2):
    ## reuniune a U b
    
    listReunion = []
    duplicates = []
    for number1 in list1:
        listReunion.append(number1)
       
    # l1: a, b, c, d
    # l2: b, c, d, e
    # l1 U l2: R = a, b, c, d, e
    # copy l1: a, b, c, d
    # b in l1? yes - go next; no - put it in R    
    for number2 in list2:
        for number1 in listReunion:
            if number2 in listReunion:
                continue
            else:
                listReunion.append(number2)

    return listReunion

list1 = [1, 2, 3, 4]
list2 = [3, 4, 5, 6]

print("Reunion of " + str(list1) + " and " + str(list2) + " is " + str(operationReunion(list1, list2)))

def operationIntersection(list1, list2):
    listIntersection = []

    for number1 in list1:
        for number2 in list2:
            if number1 == number2:
                listIntersection.append(number1)
    return listIntersection


list1 = [1, 2, 3, 4]
list2 = [3, 4, 5, 6]

print("Intersection of " + str(list1) + " and " + str(list2) + " is " + str(operationIntersection(list1, list2)))

def operationComplement(list1, list2):
    listComplement = []

    # l1 = a, b, c
    # l2 = b, c
    # l1/ l2 = a

    for number1 in list1:
       if number1 in list2:
           continue
       else:
           listComplement.append(number1)

    return listComplement


list1 = [1, 2, 3, 4]
list2 = [3, 4, 5, 6]

print(str(list1) + " complement of " + str(list2) + " is " + str(operationComplement(list1, list2)))

# Ex 5
# lista = [1, 2, 3, 4] len(lista) = 4
# k = 3 
# [(1, 2, 3), (1,2, 4), (1, 3, 4), (2, 3, 4)

import itertools
def combinationList(list, k):

    for i in range(0, len(list) + 1, 1):   
        for subset in itertools.combinations(list, i):
           if len(subset) == k:
               print(subset)


lista = [1, 2, 3, 4]
combinationList(lista, 3)

# Ex 6
# l1: [1,2, 3]; l2: [2, 3, 4]; l3: [4, 5, 6]; l4: [4, 1, "test]
# x = 2
# returneaza [1, 2, 3]

def howManyInList(*lists, x):
    count = 0
    newList = []

    for list in lists:
        for i in range (0, len(list), 1):
            if i in lists[1:]:
                count = count + 1

            if count == x:
                print(i)

list1 = [1, 2, 3]
list2 = [2, 3, 4]
list3 = [4, 5, 6]
list4 = [4, 1, "text"]
# howManyInList(list1, list2, list3, list4, 2)

 # Ex 7

 # Ex 8 

def  changingLists(*lists):
    position = 0
    newList = []

    for list in lists: 
        for element in list:
            for i in range(0, len(list), 1):
                if i == position:
                    newList.append(i)

    return newList