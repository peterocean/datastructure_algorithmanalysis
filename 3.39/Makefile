CC = gcc
CFLAGS  = -g -o

stack_test:stack_test.o stack.o
	$(CC) $(CFLAGS)  $@ $^
stack.o:stack.h
	gcc -g -c stack.c
stack_test.o:stack.h
	gcc -g -c stack_test.c -o stack_test.o	
clean:
	rm -f  stack_test *.o
