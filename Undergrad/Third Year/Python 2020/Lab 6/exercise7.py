# Verify using a regular expression whether a string is a valid CNP.

import re

def isValidCNP(CNP):
    r = re.compile("[1-8][0-9][0-9][0-1][0-2][0-3][0-9][0-5][0-9][0-9][0-9][1-9][0-9]")

    if r.match(CNP):
        return True
    return False


print(isValidCNP("2991121018929"))