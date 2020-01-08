
#  Implement using the socket module (TCP),
#  a server that writes when a client connects
# to it the following data: the connection time in 
# human-readable format, the address, and the port of the client.

import socket
import time

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind(("127.0.0.1", 1234))
s.listen(1)

(connection, address) = s.accept()
(peer_addr, peer_port) = connection.getpeername();

print("Connected address:", address)
print("Connection time: ", time.asctime())
print("Client port: ", peer_port)

connection.close()
print("Server closed")