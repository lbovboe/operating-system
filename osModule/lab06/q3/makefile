# makefile for teststack
# the filename must be either Makefile or makefile
$(CC) = gcc
main:main.o token.o
	$(CC) main.o token.o -o main
token.o:token.c token.h
	$(CC) -c token.c
main.o:main.c
	$(CC) -c main.c
clean:
	rm *.o teststack