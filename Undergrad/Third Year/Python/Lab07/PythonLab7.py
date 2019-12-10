def greatest_common_divisor_2_numbers(a, b):
    while(b):
        a, b = b, a % b
    return a
    
def greatest_common_divisor(*numbers):

    divisors = 0
    a = numbers[0]
    for number in numbers[1:]: 
        divisors = greatest_common_divisor_2_numbers(a, number)
    return divisors

#print(greatest_common_divisor(10, 5))

def vowels_in_string(string):

    count_vowels = 0
    list_vowels = []

    vowels = "aeiouoAEIOU"
    for character in string:
        if character in vowels:
            count_vowels = count_vowels + 1
            list_vowels.append(character)
    return count_vowels, list_vowels

#print(vowels_in_string("heey"))

def occurrences_first_string_in_second(string1, string2):

    count = 0

    while string1 in string2:
        string2 = string2.replace(string1, "", 1)
        count = count + 1
    return count

#print(occurrences_first_string_in_second("meow", "meowmeowmeow"))

# CamelCase -> camel_case
def snake_case(string):

    snake_string = ""

    for character in string:
        if character == string[0]:
            snake_string += character.lower()

        elif character == character.lower():
            snake_string += character

        else:
            snake_string += "_{}".format(character.lower())

    return snake_string

#print(snake_case("iAmBigCat"))

# To do:
#def matrix_in_spiral_order(rows, columns, vector):

def the_n_th_fibonacci_number(number):
    fibonacci_list = []
    
    sum_last_two = 0
    number1 = 0
    number2 = 1
    for index in range(0, number):
        fibonacci_list.append(number2)

        sum_last_two = number1 + number2
        number1 = number2
        number2 = sum_last_two

    return fibonacci_list[-1]

#print(the_n_th_fibonacci_number(10))

def first_n_numbers_fibonacci(number):
    fibonacci_list = []

    sum_last_two = 0
    number1 = 0
    number2 = 1

    for index in range(0, number):

        fibonacci_list.append(number2)

        sum_last_two = number1 + number2
        number1 = number2
        number2 = sum_last_two

    return fibonacci_list

#print(first_n_numbers_fibonacci(10))

def is_prime(number):

    if number == 1:
        return False
    
    if number == 2:
        return True

    for index in range(2, number):
        if number % index == 0:
            return False
    return True

#print(is_prime(23))

def prime_numbers_found_in_list(list):
    prime_list = []

    for number in list:
        if is_prime(number):
            prime_list.append(number)

    return prime_list

#list = [1, 2, 3, 4, 5]
#print(prime_numbers_found_in_list(list))

def find_one_line(point1, point2):
    # (x1, y1), (x2, y2) points
    slope = (point2[1] - point1[1])/ (point2[0] - point1[0])
    b = point1[1] - slope * point1[0]

    line = (slope, -1, b)

    return line

#point1 = (1,1)
#point2 = (2, 3)
#print(find_one_line(point1, point2))

def list_unique_lines(list_of_points):
    list_of_lines = []

    for point1, point2 in zip(list_of_points, list_of_points[1:]):
        list_of_lines.append(find_one_line(point1, point2))

    return list_of_lines

#list_of_lines = [(1, 1), (2, 3)]
#print(list_unique_lines(list_of_lines))

def a_reunited_b(list1, list2):
    reunited_list = []

    # copy first element
    for element in list1:
        reunited_list.append(element)

    for element2 in list2:
        for element1 in reunited_list:
            # check if the elements from list2 are in list1:
            if element2 in reunited_list:
                # skip if they are
                continue
            else:
                reunited_list.append(element2)

    return reunited_list

#list1 = [1, 2, 3]
#list2 = [3, 4, 5]
#print(a_reunited_b(list1, list2))

def a_intersected_b(list1, list2):
    different_values = []
    same_values = []

    for element1 in list1: 
        for element2 in list2:
            if element1 == element2:
                same_values.append(element1)
            else:
                different_values.append(element1)

    return same_values

#list1 = [1, 2, 3]
#list2 = [3, 4, 5]
#print(a_intersected_b(list1, list2))

def a_minus_b(list1, list2):
    not_in_b = []

    for element1 in list1:
            if element1 in list2:
                continue
            else:
                not_in_b.append(element1)

    return not_in_b

#list1 = [1, 2, 3]
#list2 = [3, 4, 5]
#print(a_minus_b(list1, list2))

# Another way of doing this?
import itertools
def combinations(list, length):
    combination_list = [] 

    for i in range(0, len(list)):
        for subset in itertools.combinations(list, i):
            if len(subset) == length:
                combination_list.append(subset)

    return combination_list

#list1 = [1, 2, 3, 4]
#print(combinations(list1, 3))

def big_list(lists):
    # return [x for list in lists for x in list]

    result = []
    for list in lists:
        for x in list:
            result.append(x)
    return result

def exactly_x_times_in_list(x, *lists):
    list_exactly_x = []

    elements = big_list(lists)

    for e in elements:
        if elements.count(e) == x:
            list_exactly_x.append(e)

    return list(set(list_exactly_x))

#list1 = [1, 2, 3]
#list2 = [3, 4, 5]
#print(exactly_x_times_in_list(2, list1, list2))

# 7. character not seen
def ascii_divisible_flag_true(x, *strings):
    list_ascii = []
    list_ascii_divisible_x = []

    for string in strings:
        for character in string:
            list_ascii.append(ord(character))

    print(list_ascii)
    for character in list_ascii:
        character_int = int(character)
        if character_int % x == 0:
            list_ascii_divisible_x.append(chr(character_int))

    return list_ascii_divisible_x

#print(ascii_divisible_flag_true(2, "abc"))

# zip(p) : zip([[1, 2, 3], [4, 5, 6]]) : [(1, 2, 3), (4, 5, 6)]
# zip(*p) : zip([1, 2, 3], [4, 5, 6]) : [(1, 4), (2, 5), (3, 6)]
def tuples_list(*lists):
    list_tuple = []

    list_tuple = list(zip(*lists))
    return list_tuple

#list1 = [1, 2, 3]
#list2 = [3, 4, 5]
#print(tuples_list(list1, list2))

def order_3rd_character_2nd_element(*tuples):
    list_tuples = []
    
    for tuple in tuples:
        list_tuples.append(tuple)

    list_tuples_sort = sorted(list_tuples, key = lambda x: x[1][2])

    return list_tuples_sort

#print(order_3rd_character_2nd_element(('abc', 'zza'), ('abc', 'abc')))

def set_operations(set1, set2):

    set = { (frozenset(set1).intersection(set2)), 
            (frozenset(set1).union(set2)),
            (frozenset(set1).difference(set2)),
            (frozenset(set2).difference(set1))
          }
    return set

def set_intersection(list1, list2):
    set1 = set(list1)
    set2 = set(list2)

    intersection = {}

    intersection = set1.intersection(set2)
    return intersection

#list1 = [1, 2, 3]
#list2 = [3, 4, 5]
#print(set_intersection(list1, list2))

def set_union(list1, list2):
    set1 = set(list1)
    set2 = set(list2)
    
    union = {}

    union = set1.union(set2)
    return union

#list1 = [1, 2, 3]
#list2 = [3, 4, 5]
#print(set_union(list1, list2))

def set_difference(list1, list2):
    set1 = set(list1)
    set2 = set(list2)

    difference = {}

    difference = set1.difference(set2)
    return difference

#list1 = [1, 2, 3]
#list2 = [3, 4, 5]
#print(set_difference(list1, list2))

def dictionary_key_characters_value_occurences(string):
    dictionary = dict()
    count = 0

    # {0 : 'c', 1 : 'a', 2 : 't'} 
    for i in range(0, len(string)):
        dictionary.update({i : string[i]})
    
    dictionary_reversed = dict()
    for i in range(0, len(string)):
        dictionary_reversed.update({string[i] : string.count(string[i])})

    return dictionary_reversed

#print(dictionary_key_characters_value_occurences("cat"))

def compare_dictionaries(dictionary1, dictionar2):
    return all(key in dictionary2 and dictionary1[key] == dictionary2[key] for key in dictionary1) and all(key in dictionary1 and dictionary1[key] == dictionary2[key] for key in dictionary2)

#dictionary1 = {
#    '0' : 'c',
#    '1' : 'b'
#    }

#dictionary2 = {
#    '0' : 'a',
#    '1' : 'b'
#    }

#print(compare_dictionaries(dictionary1, dictionary2))

# 4. To do?

# 5. What?
# rule = (key, "prefix", "middle", "suffix")
# valid value : "prefix" "middle" "suffix"
def validate_dictionary(dictionary, set_tuples):
    list_tuples = list(set_tuples)
    list_tuples.sort()

    # print(list(dictionary.values())[0])
    #for i in range(0, len(set_tuples)):
    #    for key, value in dictionary.keys(), dictionary.values():   
    #        if key != list(set_tuples)[i][0]:
    #            print(key, list(set_tuples)[i][0])
    
    return True

s = {("key1", "come", "inside", "out"), 
    ("key2", "start", "middle", "winter")}
d = {"key1": "come inside, it's too cold out", 
    "key2": "this is not valid"} 
#print(validate_dictionary(d, s))

def unique_duplicate_tuple(list):
   
    lista = []

    for i in range(0, len(list)):

        dictionary = dict()
        dictionary[list.count(list[i])] = list[i]
        lista.append(dictionary)

    lista_unique = []
    lista_duplicates = []
    
    count_unique = 0
    count_duplicates = 0

    for dictionary in lista:
        for key, value in dictionary.items():
            if key == 1:
                lista_unique.append(value)
                count_unique += 1
            elif key >= 2:
                lista_duplicates.append(value)
                count_duplicates += 1

    return count_unique, count_duplicates

#list = [1, 2, 2, 2, 3]
#print(unique_duplicate_tuple(list))

# 7. To do
def sets_to_dictionary(*sets):
    dictionary = dict()

    for set1, set2 in zip(list(sets), list(sets)[1:]):
        dictionary.update({str(set1) + ' union ' +  str(set2) : set_union(set1, set2)})

    return dictionary
       

set1 = {1, 2}
set2 = {2, 3}
set3 = {3, 4}
#print(sets_to_dictionary(set1, set2, set3))

def sort_tuples_after_first_name(list_of_tuples):
    list = sorted(list_of_tuples, key = lambda x: x[1])
    return list

#list = [("Rindasu", "Andreea"), ("Mihai", "Ana")]
#print(sort_tuples_after_first_name(list))

def name_in_list(list_of_tuples, first_name):
    sorted_list = sorted(list_of_tuples, key = lambda x: x[1])

    for i in range(0, len(list_of_tuples)):
        if sorted_list[i][1] == first_name:
            return True
    return False

#list = [("Rindasu", "Andreea"), ("Mihai", "Ana")]
#print(name_in_list(list, "Anaa"))

# 4. ?

# 5.
def dictionary_all_keys_and_values(*dictionaries):
    dictionary_all = dict()

    for dictionary in dictionaries:
        for key, value in dictionary.items():
            if key in dictionary_all.keys():
                all_value = dictionary_all.get(key)
                if isinstance(all_value, list):
                    dictionary_all.get(key).append(value)
                else:
                    dictionary_all.update({key : [value, all_value]})
            else:
                dictionary_all.update({key : value})

    return dictionary_all
 
#dictionary1 = {'a' : '1', 'b' : 2}
#dictionary2 = {'a' : '2'}
#dictionary3 = {'a' : '3'}
#print(dictionary_all_keys_and_values(dictionary1, dictionary2, dictionary3))

def problem1(my_list):
    list_odd = []
    list_even = []

    for i in my_list: 
        if i % 2 > 0:
            list_odd.append(i)
        else:
            list_even.append(i)
     
    concatenate_list = []

    for x, y in zip(list_even, list_odd):
        concatenate_list.append(tuple((x, y)))
                
    return concatenate_list


#list = 	[1, 3, 5, 2, 8, 7, 4, 10, 9, 2]
#print(problem1(list))

def problem2(pairs):

    res = dict((idx[0], idx[1]) for idx in pairs)
    sum = 0
    prod = 1
    pow = 1

    mylist =[]
    for k,v in res.items():
        newDict = {}
        sum = k + v
        prod = k * v
        pow = k**v
        newDict['sum']=sum
        newDict['prod']= prod
        newDict['pow']=pow
        mylist.append(newDict)

    return mylist

#print(problem2([(2, 3), (5, 6)]))


def problema4(my_list):
    my_list1 = [x for x in my_list if type(x) == int]
    
    my_list1.sort(reverse = True)
    return my_list1


#list = [1, 2, 'trei', 4, [5, 6]]
#x = problema4(list)
#print(x)

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

#x = problema3(5)
#print(x)


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