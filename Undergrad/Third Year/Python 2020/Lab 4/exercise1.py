# Să se scrie o funcție ce primeste un singur parametru, director,
# ce reprezintă calea către un director.
# Funcția returnează o listă cu extensiile unice sortate
# crescator (in ordine alfabetica) a fișierelor din directorul
# dat ca parametru.
# Mențiune: extensia fișierului ‘fisier.txt’ este ‘txt’

import os

def sortExtensions(directoryPath):
    files = []
    for file in os.listdir(directoryPath):
        if not os.path.isdir(file):
            files.append(file)

    extensions = set()
    for file in files:
        extensions.add(os.path.splitext(file)[1])

    return sorted(extensions)


print(sortExtensions("C:\\Users\\Andreea Rindasu\\PycharmProjects\\PythonClass\\Lab 3"))