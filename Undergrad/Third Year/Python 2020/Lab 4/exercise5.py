# Să se scrie o funcție care primește ca argumente două șiruri
# de caractere, target și to_search șireturneaza o listă de
# fișiere care conțin to_search. Fișierele se vor căuta
# astfel: dacă target este un fișier, se caută doar in fișierul
# respectiv iar dacă este un director se va căuta recursiv in
# toate fișierele din acel director. Dacă target nu este nici
# fișier, nici director, se va arunca o excepție de tipul
# ValueError cu un mesaj corespunzator.

# returns a list of files which contain to_search

import os

def function5(target, to_search):
    if os.path.isfile(target):
        filesFound = []

        with open(target) as f:
            if to_search in f.read():
                filesFound.append(target)
        f.close()

        return filesFound

    elif os.path.isdir(target):
        filesFound = []
        for currentPath, folders, files in os.walk(target):
            for file in files:
                filePath = os.path.join(currentPath, file)
                filesFound.extend(function5(filePath, to_search))

        return filesFound
    else:
        raise ValueError("Target is not a file and it is not a directory.")


try:
    print(function5("C:\\Users\\Andreea Rindasu\\PycharmProjects\\PythonClass\\Lab 4\\Exercise5Directory", "ana"))
except ValueError as e:
    print(e)
