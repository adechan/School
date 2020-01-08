# Implement using the socket module (UDP), 
# a server that when is receiving a UDP 
# packet (datagram) writes in a text file 
# the following information: time and date, 
# address, port, length, md5 hash of the content 
# in hex format, sha256.


import socket
import os
import hashlib
import time

s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
s.bind(("127.0.0.1", 1234))

while True:
	print("waiting for client")
	data, addr = s.recvfrom(1024)
	peer_addr, peer_port = s.getsockname();
	print("Connection time: {}".format(time.asctime()))
	print("received message: ", data)
	print("Address: ", addr)
	print("Port: {}".format(peer_port))
	
	with open("udp_server", "w+") as f:
		f.write("Time and date: {}\n".format(time.asctime()))
		f.write("Address: {}\n".format(addr))
		f.write("Port: {}\n".format(peer_port))
		f.write("Packet Length: {}\n".format(len(data)))

		m = hashlib.md5()
		m.update(data)
		f.write("Md5 hash: {}\n".format(m.hexdigest()))

		sha = hashlib.sha256()
		sha.update(data)
		f.write("Sha256 hash: {}\n".format(sha.hexdigest()))

print("Server closed")

