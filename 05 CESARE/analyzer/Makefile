CC          = gcc
CLINKER     = $(CC)

all: analyzer

analyzer: analyzer.o liv2.o liv3.o liv4.o liv7.o ssh.o util.o glob.o
	$(CLINKER) -o analyzer analyzer.o liv2.o liv3.o liv4.o liv7.o ssh.o util.o glob.o /usr/lib/libpcap.dylib


clean:
	/bin/rm -f *.o analyzer


.c.o:
	$(CC) -c $*.c
