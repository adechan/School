
#  Implement a client for the deployed server at 1a: 
#  a script that receives from the command line a 
#  string addr and an integer port and connects through 
#  TCP to the addr address at the port port.

import sys
import socket
import time

str_address = sys.argv[1]
int_port = int(sys.argv[2])

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

s.connect((str_address, int_port))
s.send(b"Hello there!")
s.close()