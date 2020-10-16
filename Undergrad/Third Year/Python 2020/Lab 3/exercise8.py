# Write a function that receives a single dict parameter named mapping.
# This dictionary always contains a string key "start". Starting
# with the value of this key you must obtain a list of objects by
# iterating over mapping in the following way: the value of the
# current key is the key for the next value, until you find a loop
# (a key that was visited before). The function must return the list
# of objects obtained as previously described.

# need to fix it!

def loop(dictionary):
    visited = []
    nextKey = ""

    for t in dictionary.items():
        if t[0] == "start":
            visited.append(t[1])
            nextKey = t[1]

        if t[0] == nextKey and t[1] != "start":
            visited.append(t[1])
            nextKey = t[1]

    return visited

print(loop({'start': 'a', 'b': 'a', 'a': '6', '6': 'z', 'x': '2', 'z': '2', '2': '2', 'y': 'start'}))
# print(loop({"start": "a", "a": "6", "6":"3"}))
