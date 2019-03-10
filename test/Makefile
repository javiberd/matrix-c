# Description: Simple makefile for compiling the test and the library.
# Library is compiled by calling its make file.
# Author: Javier Berdecio Trigueros

PROGRAM = matrix_test

CC			=	gcc
CFLAGS  = -Wall
LDFLAGS =

all: $(PROGRAM)

$(PROGRAM): ../obj/matrix.o obj/test.o
	$(CC) $(LDFLAGS) ../obj/matrix.o obj/test.o -o $@

../obj/matrix.o:
	$(MAKE) -C ../

obj/test.o: src/test.c
	mkdir -p obj/
	$(CC) $(CFLAGS) -c src/test.c -o obj/test.o

clean:
	rm -f $(PROGRAM)
	rm -f obj/test.o
	$(MAKE) -C ../ clean
