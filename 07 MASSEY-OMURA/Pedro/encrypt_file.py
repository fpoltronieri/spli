import os
import sys
import string
import math

def encrypt(key,inputfile,outputfile,keyp,prime):

	#Prova classica con apertura file binario
	keyfile = open(key,"wb")
	infile = open(inputfile,"rb")
	outfile = open(outputfile,"wb")

	# reading tga content
	content = infile.read()
	header = content[:18]
	body = content[18:]

	# generating random key
	# use small prime number in respect of Massey Omura condition
	# ea 41 da 61 p 251
        # eb 59 db 89 p 251		
	#randomGen = open('/dev/urandom','rb')
	infile_lenght = len(body)#os.fstat(infile.fileno()).st_size
	#pad = randomGen.read(infile_lenght)
	#keyfile.write(pad)
	keyfile.close()
	#randomGen.close()
	
	

	# writing header of tga image
	outfile.write(header)
	for i in range(0, infile_lenght):
		#temp = ((byte[i] & shiftmask) << shiftn) | ((byte[i] & shiftmask2) >> shiftn2)
		n = ord(body[i])
		n = pow(n,keyp)%prime
		nc = chr(n)
		outfile.write(nc)

	infile.close()
	outfile.close()


	#Lo stesso problema c'e se hai 255 e sommi va in crisi
