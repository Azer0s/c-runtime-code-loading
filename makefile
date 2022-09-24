CC=gcc
CFLAGS=
BIN=main
PAYLOAD=func.bin

.PHONY: clean

all:
	$(MAKE) clean
	$(CC) $(CFLAGS) main.c -o bin/$(BIN)
	nasm func.asm -o bin/$(PAYLOAD)
	./bin/main

clean:
	rm -rf bin/ || true
	mkdir bin || true
