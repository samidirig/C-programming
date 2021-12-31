CC = gcc

CFLAGS=-c 	-Wall

all:makeProgram

makeProgram: matrixCarpim.o
	$(CC)	matrixCarpim.o -o makeProgram

matrixCarpim.o: matrixCarpim.c
	$(CC)	$(CFLAGS)	matrixCarpim.c

clean:
	del *.o makeProgram.exe
