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
    dictionary = dict()

    sum = 0
    prod = 1
    pow = 1

    #dictionary = dict((index[0], index[1]) for index in pairs)
    #for key, value in dictionary.items():

    for pair in pairs:
        dictionary.update({'sum' : pair[0], 'prod': 3, 'pow' : 4})

    return dictionary

pairs = [(1,2), (4,3)]
print(problem2(pairs))