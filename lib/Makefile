CC=gcc
CFLAGS=-Wall -Wextra -std=c11 -Wpedantic -I include/
OBJ=mutators.o

libdfuzz.so: $(OBJ)
	$(CC) -shared -o $@ $^ $(CFLAGS)

%.o: %.c
	$(CC) -c -fPIC -o $@ $< $(CFLAGS)

install: libdfuzz.so
	ln -s $(CURDIR)/$^ /usr/lib

uninstall:
	rm /usr/lib/libdfuzz.so

clean:
	rm -f *.o *.so
