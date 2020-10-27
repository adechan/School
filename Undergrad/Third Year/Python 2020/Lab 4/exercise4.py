# Să se scrie o funcție ce returnează o listă cu extensiile unice a fișierelor
# din directorul dat ca argument la linia de comandă (nerecursiv). Lista
# trebuie să fie sortată crescător.
# Mențiune: extensia fișierului ‘fisier.txt’ este ‘txt’, iar ‘fisier’
# nu are extensie, deci nu va apărea în lista finală.

import sys
import os

def uniqueExtensions(directory):
    print("The directory is " + directory)

    extensions = []
    for file in os.listdir(directory):
        # print(file)
        if os.path.splitext(file)[1] == "":
            continue
        extensions.append(os.path.splitext(file)[1])

    return sorted(list(set(extensions)))


directory = sys.argv[1]
print(uniqueExtensions(directory))