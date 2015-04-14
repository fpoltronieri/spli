import os
import sys

from decoder import Decoder
from encoder import Encoder

def bin (s):
    return str(s) if s<=1 else bin(s>>1) + str(s&1)

if __name__ == '__main__':

    a = 0b0001
    for i in range(0, 16):
        a = a + 1
        print bin(a)


    # checking arguments
    if len(sys.argv) < 3:
        print "BAD USAGE:"
        print "python caesar.py encode filename key"
        print "python caesar.py decode filename [key]"
        sys.exit(0)
    
    # selected mode
    mode = sys.argv[1]

    # selected filename
    filename = sys.argv[2]

    #selected key
    if len(sys.argv) == 3:
        key = "bruteforce"
    else:
        key = int(sys.argv[3], 10)

    # check if you passed the right value
    if (isinstance(key, str)) and (mode == "encode"):
        print "ERROR: use a int value for key"
        print "BAD USAGE: pyhon caesar.py encode filename key"
        sys.exit(0);

    # printing parameters
    print "Selected mode: " + mode
    print "Selected file: " + filename
    print "Selected key: " + str(key)

    # check if file exists
    if not os.path.isfile(filename):
        print "ERROR: File doesn't exists."
        sys.exit(0)

    # creating encoder or decoder
    if mode == "encode":
        encoder = Encoder()
    else:
        decoder = Decoder()
