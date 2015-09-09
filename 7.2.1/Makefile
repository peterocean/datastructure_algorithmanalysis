CC = gcc
CFLAGS  = -g -o

sort_test:sort_test.o sort.o
	$(CC) $(CFLAGS)  $@ $^
sort.o:sort.h sort.c
	gcc -g -c sort.c
sort_test.o:sort_test.c sort.h
	gcc -g -c sort_test.c -o sort_test.o	
clean:
	rm -f  sort_test *.o
