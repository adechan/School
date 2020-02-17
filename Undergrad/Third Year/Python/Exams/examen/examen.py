import re
def problema1(sir):
	count = 0 
	regex = re.compile("[0-9]+")
	for character in sir:
		if regex.match(character):
			count = count + 1

	return count

import urllib
from urllib import request
import json

def problema2(url):
	dict = {}

	response = urllib.request.urlopen(url).read()
	text = response.decode("utf-8")
	s = json.dumps(text)
	#print(s)

	open("serialization.json", "wt").write(s)

	data = open("serialization.json", "rt").read()
	d = json.loads(data)
	print(d)

	

#print(problema2("https://pastebin.com/raw/2ngjcGKn"))

import zipfile
import os

def is_file(path):
    if os.path.isfile(path):
        return True
    return False

def md5(file):
	m = hashlib.md5()
	with open(file) as f:
		m.update(f.read().encode())
		return m.hexdigest()


import hashlib
def problema4(my_path):
	list = []
	z = zipfile.ZipFile(my_path)
	for i in z.infolist():
		if is_file(i.filename):
			with open(i.filename, "rb") as f:
				list.append(md5(i.filename))

	list.sort()
	return list

#print(problema4("C:/Users/Andreea Rindasu/source/repos/examen/New Folder2.zip"))