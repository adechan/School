# Curs 7
# TIME MODULE
import time

print(time.ctime())  # --> Wed Jan 13 12:46:19 2021 (full time)
print(time.time())  # --> time in seconds
# localtime, gmtime parameter: number of seconds from 1970
# if it's not provided: the time object will be the time based on current time value
# not provided = time.time() => current seconds

# all the same
print(time.localtime())
print(time.gmtime())
print(time.localtime(time.time()))

# MKTIME: from time object to float number
# ASCTIME: from time object to string number

# STRFTIME: used with string representation
# %H: hour in 24 hour format
# %I: hour in 12 hour format
# %Y: year (4 digits)
# %m: month (number)
# %B: month (name)
# %M: minute
# %S: seconds
# %A: day of week (name)
# %d: day of month (number)
# %p: AM or PM

# HASHLIB MODULE
import hashlib

# each hashlib object has an update function (needs bytes)
# and a digest or hexdigest function to compute the final hash

def ex1():
    m = hashlib.md5()
    m.update(b"Hello there")
    result = m.hexdigest()
    print("Hexdigest: " + result)
ex1()

# DATA SERIALIZATION
# JSON
# SERIALIZATION
# dump: creates a json with the given info
# json.dump (file)
# json.dumps (string)

# DE-SERIALIZATION
# load: puts the json from string/ file in a variable
# json.load (file)
# json.loads (string)

# PICKLE: only for binary
# MARSHAL: only for binary

# RANDOM MODULE
import random
print(random.random())  # --> random number ex. 0.8
print(random.randint(5, 10))  # --> random int in [5, 9)

# ZIPFILE MODULE
