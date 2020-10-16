# Write a function that receives as a parameter a set and returns a
# tuple (a, b), representing the number of unique elements in the
# set, and b representing the number of duplicate elements in the set.

def uniqueAndDuplicates(set):
    unique = len(set)
    duplicates = 0
    return (unique, duplicates)


print(uniqueAndDuplicates({1, 2, 3, 4, 5, 5}))