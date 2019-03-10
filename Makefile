# Description: Simple makefile for compiling the library.
# Author: Javier Berdecio Trigueros

CC = gcc
CFLAGS = -Wall

all: obj/matrix.o

obj/matrix.o: src/matrix.c
	mkdir -p obj/
	$(CC) $(CFLAGS) -c src/matrix.c -o obj/matrix.o

clean:
	rm obj/matrix.o
