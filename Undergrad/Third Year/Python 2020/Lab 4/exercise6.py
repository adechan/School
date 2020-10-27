# Să se scrie o funcție care are același comportament ca funcția
# de la exercițiul anterior, cu diferența că primește un parametru
# în plus: o funcție callback, care primește un parametru, iar
# pentru fiecare eroare apărută în procesarea fișierelor, se va
# apela funcția respectivă cu instanța excepției ca parametru


import os

def callback(e):
    print(e)

def function6(target, to_search, callback):
    filesFound = []

    if os.path.isfile(target):
        try:
            with open(target) as f:
                if to_search in f.read():
                    filesFound.append(target)
            f.close()
        except OSError as e:
            callback(e)

        return filesFound

    elif os.path.isdir(target):
        for currentPath, folders, files in os.walk(target):
            for file in files:
                filePath = os.path.join(currentPath, file)
                filesFound.extend(function6(filePath, to_search, callback))

        return filesFound
    else:
        callback(ValueError("Target is not a file and it is not a directory."))
        return filesFound

print(function6("C:\\Users\\Andreea Rindasu\\PycharmProjects\\PythonClass\\Lab 4\\Exercise5Director", "ana", callback))
