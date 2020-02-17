
def problema1():
    sum = 0
    for i in range(1, 11):
        sum += i
    return sum

def is_prime(n):
    if n == 1:
        return False

    for i in range(2, n):
        if n % i == 0:
            return False

    return True

def problema3(m):
    list = []

    for i in range (1, m):
        if is_prime(i):
            list.append(i)
    return list

def problema4(my_list):

    list_float = []

    for number in my_list:
        if type(number) != int:
            continue
        else:
            list_float.append(number)

    list_sort = sorted(list_float, reverse = True)
    return list_sort

# n = base 8
def reverse(string):
    reversed = ''
    for i in range(len(string) - 1, -1, -1):
        reversed += string[i]

    return reversed 

def is_palindrom(string_number):
    palindroms = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']
    if string_number in palindroms:
        return True

    if string_number == reverse(string_number):
        return True
    return False

def problema5(n):

    n_string_10 = str(int(n, 8))

    print(n_string_10)
    if is_palindrom(n_string_10):
        return True

    return False

#print(problema5('145'))

# matrix = lista de liste
def problema7(matrix):
    result = []

    firstRow = matrix[0]
    length = len(matrix[0])

    for i in range (0, length):
        x = matrix[0]
        equals = True

        for row1, row2 in zip(matrix, matrix[1:]):
            if row1[i] != row2[i]:
                equals = False
                break

        if equals:
            result.append(0)
        else:
            result.append(1)

    return result

#matrix = [[1, 2, -1], [3, 1, -1], [0, 2, -1]]
#print(problema7(matrix))


#def problema7_efficient(matrix):
#    result = []

#    firstRow = matrix[0]
#    length = len(matrix[0])

#    for i in range (0, length):
#        equals = True
#        x = matrix[0][i]

#        for row in matrix[1:]:
#            if row[i] != x:
#                equals = False
#                result.append(1)
#                break
#        if equals:
#            result.append(0)

#    return result

def problema2(n, m):
    tuple = ()
    sir = [0]*(4) # ? idk
    sir[1] = 41
    sir[2] = int((1/2) * (99 - 41));
    sir[3] = 99

    i = 3
    while (sir[i] < n and sir[i] < m):
        sir[i] = 2 * sir[i - 1] + sir[i - 2]
        i = i + 1

    i = sir.index(n);
    j = sir.index(m);
    return (i, j)
   # for i in range(0, n):
   #     for j in range(0, m):

#print(problema2(41, 99))