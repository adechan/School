
import re

## EX 1
def extract_words_from_text(text):
	list_words = []
	parsed_text = re.findall("\W*\w+\s+", text)
	
	word = re.compile("[a-z0-9A-Z]+")
	for w in parsed_text:
		if word.match(w):
			list_words.append(w)

	return list_words

#print(extract_words_from_text("hel$lo $im 1ade @"))

## EX 2
def substring_match(regex, text, x):
	list = []

	parsed_text = re.findall(regex, text)

	for string in parsed_text:
		if len(string) == x:
			list.append(string)

	return list

#print(substring_match("[a-z]+", "ade123a1cat", 3))

def substrings_of(string, substring_length):
	substrings = []

	# string  = "hello"
	# for i in range(0, 5 - 3 + 1) = for i in range(0, 3)
	# string[0 : 0 + 3] = hel
	# string[1 : 1 + 3] = ell
	# string[2 : 2 + 3] = llo

	for i in range(0, len(string) - substring_length + 1):
		substrings.append(string[i : i + substring_length])

	return substrings

def substring_match2(regex, text, x):
	list = []

	parsed_text = re.findall(regex, text)

	for m in re.findall(regex, text):
		#print(substrings_of(m, x))
		for substring in substrings_of(m, x):
			list.append(substring)

	return list

#print(substring_match2("[0-9]+", "ade123a1ca234t", 3))

## EX 3
def strings_match_at_least_one_expression(string, list_expressions):
	list_matched = []

	parsed_text = ''
	for regex in list_expressions:
		parsed_text = re.compile("(" + regex + ")")

		if parsed_text.search(string):
			list_matched.append(parsed_text.search(string).group(1))

	return list_matched

#list_expressions = ["[0-9]+", "[a-z]+"]
#string = "ade1"
#print(strings_match_at_least_one_expression(string, list_expressions))

## EX 4

## EX 5

## EX 6

## EX 7
def valid_CNP(cnp):
	if len(cnp) != 13:
		return False

	regex = re.compile("[1-8]+[0-9][0-9]+[1-12]+[0-9][1-9]+[0-5][0-9]+[0-9][0-9]1?[0-9][0-9]")
	if regex.match(cnp):
		return True
	return False

#print(valid_CNP("2791463582791"))

## EX 8
# scroll a directory and displays those files whose 
# name matches a regular expression igven as parameter
# or contains a string that matches the same expressions

# files that satisfy both: will be prefixed with ">>"
import os

def is_file(path):
	if os.path.isfile(path):
		return True
	return False

def search_by_content(target, regex, list = []):
	if is_file(target) == True:
		regex_in_filename = False
		regex_in_file = False

		regex_compile = re.compile(regex)
		with open(target) as f:
			if regex_compile.search(f.read()):
				regex_in_file = True

		if regex_compile.search(target):
			regex_in_filename = True

		if regex_in_filename and regex_in_file:
			list.append(">>{}".format(target))

		elif regex_in_filename or regex_in_file:
			list.append(target)

	if is_file(target) == False:
		os.chdir(target)
		for file in os.listdir("."):
			search_by_content(file, regex, list)

	return list

#regex = "ade"
#print(search_by_content("C:\\Users\Andreea Rindasu\\source\\repos\\PythonLab11\\ade", regex))

## EX 10
def is_file(path):
	if os.path.isfile(path):
		return True
	return False

import hashlib

def md5(file):
	m = hashlib.md5()
	with open(file) as f:
		m.update(f.read().encode())
		return m.hexdigest()

def find_duplicates(directory):
	os.chdir(directory)
	list = []
	hashes = []
	same_values = []
	different_values = []
	count = 0


	for file in os.listdir('.'):
		hashes.append((file, md5(file)))
		
	for hash in hashes[1]:
		if hash not in list:
			list.append(hash)

	for element1 in hashes[1]:
		for element2 in list:
			if element1 != element2:
				different_values.append(element1)
			else:
				same_values.append(element1)

	return different_values

def find_duplicates2(directory):
	os.chdir(directory)
	hashes = {}

	for file in os.listdir('.'):
		hash = md5(file)
		if not hashes.get(hash):
			hashes[hash] = [file]
		else:
			hashes[hash].append(file)

	return hashes

#print(find_duplicates2('C:/Users/Andreea Rindasu/source/repos/PythonLab11/ade/meow'))









# Problem 1

#import re
#def parse_access_log(file):
#	access_log_ip = re.compile('\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3} \- \-')

#	ip_occurences = {}

#	with open(file) as f:
#		for match in re.findall(access_log_ip, f.read()):
#			if not ip_occurences.get(match):
#				ip_occurences[match] = 1
#			else:
#				ip_occurences[match] = ip_occurences[match] + 1
			
#	ips = []

#	for ip in ip_occurences:
#		ips.append((ip[0 : len(ip) - 4], ip_occurences[ip]))

#	ips.sort(key = lambda x: x[1], reverse = True)
#	return ips[:7]

#def problem1(path, access_logs = []):
#	if is_file(path):
#		access_logs.append(parse_access_log(path))
#	else:
#		os.chdir(path)
#		for file in os.listdir('.'):
#			problem1(file, access_logs)
	
#	# Flatten list of logs to one single big log then sort it
#	access_logs = [ip for log in access_logs for ip in log]
#	access_logs.sort(key = lambda x: x[1], reverse = True)

#	# Only get the top 7 ips
#	return list(map(lambda tuple : tuple[0], access_logs))[:7]

#print(problem1('C:/Users/Andreea Rindasu/source/repos/PythonLab11/ade/meow/access.log'))