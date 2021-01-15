# Curs 8
# SOCKET MODULE
import socket

print(socket.gethostbyname(socket.gethostname()))  # --> current system IP
print(socket.gethostbyname('uaic.ro'))  # --> convert host to IP: 85.122.16.23
print(socket.gethostbyaddr("85.122.16.7"))  # --> convert IP to host

# URL MODULE: like wget, curl (downloads the content of a web page)
# for accessing the content of a URL
# URLLIB MODULE

# FTP MODULE: enable working with FTP servers
# SMTP MODULE: enable working with emails 