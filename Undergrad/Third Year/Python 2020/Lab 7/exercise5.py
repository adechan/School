# Write a function that receives two parameters: a_path and ext.
# The script will add all files from the a_path folder that have
# the extension ext to a zip archive named the.zip.

import os
import zipfile

def function5(a_path, ext):

    files_found = []
    zip = zipfile.ZipFile("the.zip", "w", zipfile.ZIP_DEFLATED)

    for current_root, directories, files in os.walk(a_path):
        for file in files:
            file_path = os.path.join(current_root, file)
            extension = os.path.splitext(file_path)[1]

            if extension == ext:
                files_found.append(file_path)

    for file in files_found:
        print(file)
        # write file under the name basename(file)
        zip.write(file, os.path.basename(file))

    zip.close()

    return files_found


print(function5("C:\\Users\\Andreea Rindasu\\PycharmProjects\\PythonClass\\Lab 7", ".txt"))

