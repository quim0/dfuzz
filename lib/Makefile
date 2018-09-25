NAME=dfuzz
CFLAGS=-Wall -Wextra -std=c11 -Wpedantic -I include/
OBJ=mutators.o

ifeq ($(OS),Windows_NT)
	@echo "Windows not supported"
else
	UNAME := $(shell uname)
	ifeq ($(UNAME),Darwin)
		DYLIB := lib$(NAME).dylib
		CC := clang
		INSTALL_PATH := /usr/local/lib
	else
		DYLIB := lib$(NAME).so
		CC := gcc
		INSTALL_PATH := /usr/lib
	endif
endif

install: $(DYLIB)
	ln -s $(CURDIR)/$^ $(INSTALL_PATH)

$(DYLIB): $(OBJ)
	$(CC) -shared -o $@ $^ $(CFLAGS)

%.o: %.c
	$(CC) -c -fPIC -o $@ $< $(CFLAGS)

uninstall:
	rm -f $(INSTALL_PATH)/$(DYLIB)

clean:
	rm -f *.o *.so *.dylib
