# Să se scrie o funcție care primește ca parametru un șir de
# caractere care reprezintă calea către un fișer si returnează
# un dicționar cu următoarele cămpuri: full_path = calea absoluta
# catre fisier, file_size = dimensiunea fisierului in octeti,
# file_extension = extensia fisierului (daca are) sau "",
# can_read, can_write = True/False daca se poate citi din/scrie in fisier.

import os

def detailsFile(file):
    fullPath = os.path.abspath(file)

    # os.stat(file).st_size -> bytes
    # 1 octet = 1 byte = 8 bits
    fileSize = os.stat(file).st_size

    fileExtension = os.path.splitext(file)[1]
    canRead = os.access(file, os.R_OK)
    canWrite = os.access(file, os.W_OK)

    result = {}
    result["fullPath"] = fullPath
    result["fileSize"] = fileSize
    result["fileExtension"] = fileExtension
    result["canRead"] = canRead
    result["canWrite"] = canWrite

    return result

print(detailsFile("C:\\Users\\Andreea Rindasu\\PycharmProjects\\PythonClass\\Lab 4\\exercise7_file.txt"))
# print(detailsFile("exercise7_file.txt"))