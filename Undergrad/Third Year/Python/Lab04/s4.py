
def problema4(my_list):
    my_list1 = [x for x in my_list if type(x) == int]
    
    my_list1.sort(reverse = True)
    return my_list1


list = [1, 2, 'trei', 4, [5, 6]]
x = problema4(list)
print(x)

def primeNumber(number):
    for i in range(2, number):
        if number % i == 0:
            return False
    return True

def problema3(m):
    lista_numere = []

    for i in range(2, m): 
           if primeNumber(i) == True:
               lista_numere.append(i)

    return lista_numere

x = problema3(5)
print(x)