# makefile for teststack
# the filename must be either Makefile or makefile
$(CC) = gcc
commandSep:commandSep.o
	$(CC) commandSep.o -o command
commandSep.o:commandSep.c command.h
	$(CC) -c commandSep.c
clean:
	rm *.o command