
## 1a.
#import socket
#import time
#s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
#s.bind(("127.0.0.1", 1234))
#s.listen(1)
#(connection, address) = s.accept()
#(peer_addr, peer_port) = connection.getpeername();

#print("Connected address:", address)
#print("Connection time: ", time.asctime())
#print("Client port: ", peer_port)

#connection.close()
#print("Server closed")

## 1b.
#import sys
#import socket
#import time
#str_address = sys.argv[1]
#int_port = int(sys.argv[2])

#s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
#s.connect((str_address, int_port))
#s.send(b"Hello there!")
#s.close()

## 2a.
#import socket
#s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
#s.bind(("127.0.0.1", 1234))
#(connection, address) = s.accept()

#print("Connected address:", address)

#while True:
#	print("waiting for client")
#	data, addr = s.recvfrom(1024)
#	print("received message: ", data)
#print("Server closed")

import socket
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM) # UDP
sock.sendto(b'hello', ('127.0.0.1', 1234))