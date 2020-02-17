import re

def parse(file):
	
	ip_occurences = {}
	access_log_ip = re.compile('\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3} \- \-')

	with open(file) as f:
		for match in re.findall(access_log_ip, f.read()):
			if not ip_occurences.get(match):
				ip_occurences[match] = 1
			else:
				ip_occurences[match] = ip_occurences[match] + 1

	ips = []

	for ip in ip_occurences:
		ips.append((ip[0 : len(ip) - 4], ip_occurences[ip]))

	ips.sort(key = lambda x: x[1], reverse = True)
	return ips[:7]

import os
def is_file(path):
	if os.path.isfile(path):
		return True
	return False


def problema1(path, access_logs = []):
	if is_file(path):
		access_logs.append(parse(path))

	else:
		os.chdir(path)
		for file in os.listdir('.'):
			problema1(file, access_logs)

	# access_logs = [[ (), (), () ]] 

	# flat_access_logs = [(), (), ()] 
	flat_access_logs = []

	for log in access_logs:
		for ip in log:
			flat_access_logs.append(ip)

	flat_access_logs.sort(key = lambda x: x[1], reverse = True)

	return list(map(lambda tuple : tuple[0], flat_access_logs))[:7]

print(problema1('C:/Users/Andreea Rindasu/source/repos/s11/data'))


import hashlib

def md5(file):
	m = hashlib.md5()
	with open(file) as f:
		m.update(f.read().encode())
		return m.hexdigest()


def problema2(path):
	pass