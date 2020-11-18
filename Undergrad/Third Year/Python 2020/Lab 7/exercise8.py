# Write a function that receives two parameters: a_path and to_hextract.
# If a_path is a valid zip archive and to_hextract  is a file inside the
# arhive the function will return the md5 digest for unzipped content of
# to_hextract and None otherwise.

import zipfile
import hashlib
import os

def function8(a_path, to_hextract):
    extension = os.path.splitext(a_path)[1]
    filename_to_extract = os.path.basename(to_hextract)

    if extension == ".zip":
        zip = zipfile.ZipFile(a_path)

        for i in zip.infolist():
            filename = os.path.basename(i.filename)

            if filename == filename_to_extract:
                print(i.filename)
                zip.extract(i.filename, "extracted_file")

        zip.close()

        for current_root, directories, files in os.walk("extracted_file"):
            for file in files:
                m = hashlib.md5()
                file_path = os.path.join(current_root, file)
                m.update(open(file_path, "rb").read())
                return m.hexdigest()
    else:
        return None


print(function8("C:\\Users\\Andreea Rindasu\\PycharmProjects\\PythonClass\\Lab 7\\Exercise7.zip", "C:\\Users\\Andreea Rindasu\\PycharmProjects\\PythonClass\\Lab 7\\Exercise7.zip\\file10.txt"))