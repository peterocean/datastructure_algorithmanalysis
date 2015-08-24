CC = gcc
CFLAGS  = -g -o

stack_test:stack_test.o stack_array.o
	$(CC) $(CFLAGS)  $@ $^
stack_array.o:stack.h
	gcc -g -c stack_array.c
stack_test.o:stack.h
	gcc -g -c stack_test.c -o stack_test.o	
clean:
	rm -f  stack_test *.o
