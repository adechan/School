# Write a function that receives a variable number of arguments
# and keyword arguments. The function returns a list containing
# only the arguments which are dictionaries, containing minimum
# 2 keys and at least one string key with minimum 3 characters.


def function4(*args, **kwargs):

    dictionaries = []
    for arg in args:
        if type(arg) == dict:
            dictionaries.append(arg)

    for arg in kwargs:
        if type(kwargs[arg]) == dict:
            dictionaries.append(kwargs[arg])

    # minimum 2 keys + at least one string key with 3+ characters
    selectedDictionaries = []

    for dictionary in dictionaries:
        # print(dictionary)
        if len(dictionary) < 2: # doesnt have 2+ keys
            continue

        count = 0
        for key, value in dictionary.items():
            # print(key, value)
            if type(key) == str:
                if len(key) >= 3:
                    count += 1

            if count == 2:
                break

            if count >= 1:
                # print("=> ", dictionary)
                selectedDictionaries.append(dictionary)

    return selectedDictionaries

print(function4(
 {1: 2, 3: 4, 5: 6},
 {'a': 5, 'b': 7, 'c': 'e'},
 {2: 3},
 [1, 2, 3],
 {'abc': 4, 'def': 5},
 3764,
 dictionar={'ab': 4, 'ac': 'abcde', 'fg': 'abc'},
 test={1: 1, 'test': True}
))