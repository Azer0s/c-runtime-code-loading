CC=gcc
CFLAGS=
BIN=main

.PHONY: clean

all:
	$(MAKE) clean
	$(CC) $(CFLAGS) main.c -o bin/$(BIN)
	cp func.c bin
	cd bin; ./main

clean:
	rm -rf bin/ || true
	mkdir bin || true
