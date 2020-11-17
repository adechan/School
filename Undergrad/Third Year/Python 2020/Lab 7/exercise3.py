# Write a function that will receive as parameters  two strings
# representing file paths and will return True if the files
# are identical or False otherwise.

import hashlib

def compareFiles(filepath1, filepath2):
    m = hashlib.md5()
    m.update(open(filepath1, "rb").read())
    hash1 = m.hexdigest()

    m2 = hashlib.md5()
    m2.update(open(filepath2, "rb").read())
    hash2 = m2.hexdigest()

    if hash1 == hash2:
        return True
    return False


print(compareFiles("C:\\Users\\Andreea Rindasu\\PycharmProjects\\PythonClass\\Lab 7\\Exercise3\\file1.txt", "C:\\Users\\Andreea Rindasu\\PycharmProjects\\PythonClass\\Lab 7\\Exercise3\\file2.txt"))
print(compareFiles("C:\\Users\\Andreea Rindasu\\PycharmProjects\\PythonClass\\Lab 7\\Exercise3\\file1.txt", "C:\\Users\\Andreea Rindasu\\PycharmProjects\\PythonClass\\Lab 7\\Exercise3\\file3.txt"))