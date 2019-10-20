# Set: toate elementele sunt unice intre ele

# Ex 1
# parameters: 2 lists 
# returns set of sets containing A n B, A u B, A - B, B - A

# Sets are mutable which means you can modify their value
# Set of set doesnt like mutable objects, so you need to use frozenset (which is the version of the set
# but immutable!)
# Set = {} 

def problema1(set1, set2):

    set = { (frozenset(set1).intersection(set2)), 
            (frozenset(set1).union(set2)),
            (frozenset(set1).difference(set2)),
            (frozenset(set2).difference(set1))
          }
    return set

set1 = {'1', '2'}
set2 = {'2', '3'}
print(problema1(set1, set2))

# Ex 2
# parameter: string
# returns a dictionary in which the keys are the characters in the character string
# and the values are the number of occurences of that character in the given text
# Dictionary = { key : value } 

def problem2(string):

    dictionary = dict()

    for i in range(0, len(string), 1):
        dictionary.update({i : string[i]})

    reverse_dictionary = dict()

    count = 0

    for i in range(0, len(string), 1):
        reverse_dictionary.update({ string[i] : string.count(string[i])})
    

    return reverse_dictionary

print(problem2("Ana has apples")) 

# Ex 3 
# Compare two dictionaries and  return a list of differences 

def problem3(dictionary1, dictionary2):

    # return dictionary1 == dictionary2
    # all() : returns True if all items in an iterable are true, otherwise retuns false
    # for Dictionary checks if the Keys are true! 
    return all(key in dictionary2 and dictionary1[key] == dictionary2[key] for key in dictionary1) and all(key in dictionary1 and dictionary1[key] == dictionary2[key] for key in dictionary2)

dictionary1 = {
    '0' : 'a',
    '1' : 'b'
    }

dictionary2 = {
    '0' : 'a',
    '1' : 'b'
    }

print(problem3(dictionary1, dictionary2))

# TO DO
# Ex 4
# build_xml_element(tag, content, key_value) 
# Build and return a string that represents the corresponding XML element.

def problem4(tag, content, key_value):
    string = ""

    tag_key = 0
    content_key = 1
    key_value_key = 2

    dictionary = {
        tag_key : tag,
        content_key : content,
        key_value_key : key_value
        }

    string = dictionary[tag_key] + "<href =\\" + dictionary[content_key]
    return string

print(problem4("a", "meoww", "meow"))

# Ex 5
# parameter: set of tuples that represent validation rules for a dictionary 
# rule: (key, "prefix", "middle", "suffix")
# valid value: "prefix" "middle" "suffix"
# True if the given dictionary matches all the rules

# tuple = ()

def problem5(*tuples):

    dictionary_rules = dict()
    key_value = ""
    prefix_value = ""
    middle_value = ""
    suffix_value = ""

    tuples = {(key_value, prefix_value, middle_value, suffix_value)}

    key = 0
    prefix = 1
    middle = 2
    suffix = 3

    for tuple in tuples:
        dictionary_rules = {
            key :  key_value,
            prefix : prefix_value,
            middle : middle_value, 
            suffix : suffix_value
            }
    return dictionary_rules

print(problem5("key", "prefix", "miidle", "suffix"))
