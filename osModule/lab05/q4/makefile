# makefile for teststack
# the filename must be either Makefile or makefile
$(CC) = gcc
teststack:stack.o test_stack.o
	$(CC) stack.o test_stack.o -o teststack
stack.o:stack.c stack.h
	$(CC) -c stack.c
test_stack.o:test_stack.c
	$(CC) -c test_stack.c
clean:
	rm *.o teststack