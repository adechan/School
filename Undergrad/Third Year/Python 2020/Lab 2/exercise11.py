# Write a function that will order a list of string tuples
# based on the 3rd character of the 2nd element in the tuple.

def sortList(list):
    return sorted(list, key=lambda x: x[1][2])


print(sortList([('abc', 'bcd'), ('abc', 'zza')]))
