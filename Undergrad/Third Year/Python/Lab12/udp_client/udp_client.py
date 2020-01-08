
# Implement a client for the deployed server 
# at 2a: a script that receives from the command 
# line an addr string, a port integer, and a string 
# msg, and sends a UDP packet to the addr address, 
# the port port, and the msg content.

import socket
import sys

addr_string = sys.argv[1]
port_int = int(sys.argv[2])
message_string = sys.argv[3]

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM) 
sock.sendto(message_string.encode(), (addr_string, port_int))
