
def problema1(n):
    n_binar = bin(n)
    count = 0
    for cifra in n_binar:
        if cifra == '1':
            count = count + 1
           
    return count

def patrat_perfect(n):
    for i in range (0, n):
        if i * i == n:
            return True

    return False

def problema2(n):
    x = 1

    for i in range (n, 1, -1):
        if (patrat_perfect(i)):
            return i

def reverse(string):
    reversed = ''
    for i in range(len(string) - 1, -1, -1):
        reversed += string[i]
    return reversed

def is_palindrom(string):
    palidroms = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']

    if string in palidroms:
        return True

    if string == reverse(string):
        return True

    return False

def problema3(my_list):
    
    tupla = ()
    count = 0

    for element in my_list:
        if (is_palindrom(str(element))):
            count = count + 1

    highest = 0 
    for element in my_list:
        if highest < is_palindrom(str(element)):
            highest = element
            print(highest)

    tupla = (count, highest)
    return tupla

list = 	[100, 101, 111]	
print(problema3(list))

def problema4():
    pass

def problema5():
    pass