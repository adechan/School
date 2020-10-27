# Să se scrie o funcție ce primește un parametru cu numele dir_path.
# Acest parametru reprezintă calea către un director aflat pe disc.
# Funcția va returna o listă cu toate căile absolute ale fișierelor
# aflate în rădăcina directorului dir_path.

import os

def findAllAbsolutePaths(dirPath):
    itemsFound = []
    for item in os.listdir(dirPath):
        filePath = os.path.join(dirPath, item)
        itemsFound.append(filePath)


    return itemsFound


print(findAllAbsolutePaths("C:\\Users\\Andreea Rindasu\\PycharmProjects\\PythonClass\\Lab 4\\Exercise3Directory"))