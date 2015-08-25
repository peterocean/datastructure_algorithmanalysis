CC = gcc
CFLAGS  = -g -o

queue_test:queue_test.o queue.o
	$(CC) $(CFLAGS)  $@ $^
queue.o:queue.h
	gcc -g -c queue.c
queue_test.o:queue.h
	gcc -g -c queue_test.c -o queue_test.o	
clean:
	rm -f  queue_test *.o
