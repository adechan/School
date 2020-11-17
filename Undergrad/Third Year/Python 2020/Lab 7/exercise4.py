# Write a script that receives a directory as argument and creates a JSON
# file with data about all the files in that directory. For each file,
# the following information will be displayed: file_name, md5_file,
# sha256_file, size_file (in bytes), time when the file was created
# (human-readable) and the absolute path to the file.

import os
import hashlib
import time
import json

def function4(directory):
    files = []

    for file in os.listdir(directory):
        if os.path.isdir(file):
            continue

        file_path = os.path.join(directory, file)
        file_size = os.stat(file_path).st_size
        # ctime: converts a time expressed in seconds to a string time
        file_creation = time.ctime(os.path.getctime(file_path))

        file_read = open(file_path, "rb").read()

        md5 = hashlib.md5()
        md5.update(file_read)
        hash_md5 = md5.hexdigest()

        sha256 = hashlib.sha256()
        sha256.update(file_read)
        sha256 = sha256.hexdigest()

        fileDictionary = dict()
        fileDictionary["file_name"] = os.path.basename(file)
        fileDictionary["md5_file"] =  hash_md5
        fileDictionary["sha256_file"] = sha256
        fileDictionary["file_size"] = file_size
        fileDictionary["file_creation"] = file_creation
        fileDictionary["absolute_path"] = file_path

        files.append(fileDictionary)

        serializated_json = json.dumps(files)
        open("serialization.json", "wt").write(serializated_json)

    return files


print(function4("C:\\Users\\Andreea Rindasu\\PycharmProjects\\PythonClass\\Lab 7\\Exercise3"))
