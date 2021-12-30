CC = gcc

CFLAGS=-c 	-Wall

all:makeProgram

makeProgram: main.o matrisOperations.o
	$(CC)	main.o matrisOperations.o -o makeProgram

main.o: main.c
	$(CC)	$(CFLAGS)	main.c
matrisOperations.o: matrisOperations.c matrisOperations.h
	$(CC)	$(CFLAGS)	matrisOperations.c

clean:
	del *.o makeProgram.exe

