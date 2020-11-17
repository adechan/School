# Write a function that receives two parameters: a_path and ext.
# The script will add all files from the a_path folder that have
# the extension ext to a zip archive named the.zip.

import os

def function5(a_path, ext):

    files = []

    for current_root, directories, files in os.walk(a_path):
        for file in files:
            file_path = os.path.join(current_root, file)
            extension = os.path.splitext(file_path)[1]

            if extension == ext:
                files.append(file_path)

    return files


print(function5("C:\\Users\\Andreea Rindasu\\PycharmProjects\\PythonClass\\Lab 7\\Exercise3", ".txt"))

