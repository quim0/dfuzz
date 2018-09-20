CC=gcc
CFLAGS=-Wall -Wextra -std=c11 -Wpedantic -I ../lib/include/
OBJ=test1.o

test1: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) -ldfuzz

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -f *.o
