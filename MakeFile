try : grepcode.o
	cc *.o -o project
	clear
grepcode.o : grepcode.c
	cc -c grepcode.c -c

