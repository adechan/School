# Să se scrie o funcție ce primește ca argumente două căi: director si fișier.
# Implementati functia astfel încât în fișierul de la calea fișier
# să fie scrisă pe câte o linie, calea absolută a fiecărui
# fișier din interiorul directorului de la calea folder,
# ce incepe cu litera A.

import os


def function2(directoryPath, filePath):
    files = []
    for file in os.listdir(directoryPath):
        if not os.path.isdir(file):
            files.append(os.path.basename(file))

    print(files)
    try:
        f = open(filePath, "w")
        for file in files:
            if file[0:1] == 'A':
                fullname = os.path.join(directoryPath, file)
                print(fullname)
                f.write(fullname +"\n")

        f.close()
    except:
        print("Unable to open file ", filePath)


function2("C:\\Users\\Andreea Rindasu\\PycharmProjects\\PythonClass\\Lab 4\\Exercise2Directory",
          "C:\\Users\\Andreea Rindasu\\PycharmProjects\\PythonClass\\Lab 4\\exercise2_write.txt")
