import re

def problema1(s):
	list = []
	regex = re.compile("[a-zA-Z0-9_]+")
	result = re.findall(regex, s)
	list = sorted(result)
	return list

#s = "ana are mere"
#print(problema1(s))

import urllib
from urllib import request

def problema2(s, url):
	response = urllib.request.urlopen(url).read()
	text = response.decode("utf-8")
	if s in text:
		return True

	return False

#print(problema2("facebook","https://mbasic.facebook.com/"))

import os
import hashlib

def is_file(path):
    if os.path.isfile(path):
        return True
    return False


def md5(file):
	m = hashlib.md5()
	with open(file) as f:
		m.update(f.read().encode())
		return m.hexdigest()


def problema3(path):
	os.chdir(path)
	hashes = []
	for file in os.listdir('.'):
		if is_file(file):
			hashes.append(md5(file))

	hashes.sort()
	return hashes

#print(problema3("ade"))

import sys

def problema4():
	directory = sys.argv[1]
	os.chdir(directory)
	dimensions = []

	for file in os.listdir('.'):
		if is_file(file):
			dimensions.append(os.path.getsize(file))

	dimensions.sort()
	return list(set(dimensions))	

#print(problema4())

def type_instr(x, op, y):
	if op == "egal":
		return int(y)
	if op == "plus":
		return int(x) + int(y)
	if op == "minus":
		return int(x) - int(y)
	if op == "impartit":
		return int(x) // int(y)
	if op == "inmultit":
		return int(x) * int(y)

def problema5(cod):
	list = cod.splitlines()
	x = None

	for instr in list:
		splitted = instr.split()
		instr = splitted[1]
		y = splitted[2]
		x = type_instr(x, instr, y)
	return x

#print(problema5("x egal 10"))

import datetime

def problema7():
	datetimes = []
	tuple = ()
	dates = []

	for i in range(1, len(sys.argv)):
		datetimes.append(datetime.datetime.strptime(sys.argv[i], "%m/%d/%Y_%H.%M.%S"))
	datetimes.sort(reverse=True)

	for date in datetimes:
		dates.append(date.strftime("%Y-%m-%d %H:%M:%S"))

	tuple = (dates, abs(int((datetimes[0] - datetimes[-1]).total_seconds())))
	return tuple

#print(problema7())

#def problema8(path, low, high):
