/*
* @file main.c
* @description testing program and initiliaze matrices.
* @date 16.12.2021
* @author Mahmudhan Sami Diriğ ve mahmudhansami.dirig@stu.fsm.edu.tr
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "matrisOperations.h"

int main(int argc, char *argv[]){
	// getting matrices size from user in command
	size1 = atoi(argv[1]);
	size2 = atoi(argv[2]);
	islemTipi = atoi(argv[3]);
	seed = atoi(argv[4]);
	//print variables given from command line, print as a control is variables true.
	printf("size1: %d, size2: %d, islemTipi: %d, seed: %d \n", size1, size2, islemTipi, seed);

	// find sonucMatrix size with an equation 
	int gSize,fSize,dSize;
	gSize = size1;
	fSize = size2;
	dSize = findDtype(islemTipi, fSize);
	sonucBoyut = (gSize - fSize + 2*dSize) + 1;
	
	//printf("%d \n",dSize);
    puts("\n********************************\nPROGRAM RESULTS:\n");
	size1++;
	size2++;
	sonucBoyut++;

	//initiliace matrices
	int **matrix1;
	int **matrix2;
	int **sonucMatrix;

	// fill matrices with random numbers
	if(islemTipi == 1){
		//islemTipi '1' ise D değeri kadar matrix'1 e çerçeve eklenir
		size1 = size1 + (dSize*2);
		matrix1 = allocateMatrix(size1);
    	puts("matrix1 allocated \n");
		matrix2 = allocateMatrix(size2);
    	puts("matrix2 allocated \n");
		matrixKenarliDoldur(matrix1,size1,seed,dSize);
		//matrix2 değişmeyecektir
		matrixDoldur(matrix2,size2,seed);		
	}else if (islemTipi == 0){
		// islemTipi 0 ise D değeri 0 olur ve ona göre matrisler doldurulur.
		matrix1 = allocateMatrix(size1);
    	puts("matrix1 allocated \n");
		matrix2 = allocateMatrix(size2);
    	puts("matrix2 allocated \n");
		matrixDoldur(matrix1,size1,seed);
		matrixDoldur(matrix2,size2,seed);
	}else{
		puts("Islem Tipi hatali...!");
		exit(0);
	}
	//print matrix1 as an output
	printf("Matrix1 %dx%d: ", size1-1, size1-1);
	printMatrix(matrix1, size1-1);
	//print matrix2 as an output
	printf("Matrix2 %dx%d: ", size2-1, size2-1);
	printMatrix(matrix2, size2-1);
	// getting sonucMatrix after from the operation method and writing it.
	sonucMatrix = operasyon1(matrix1, matrix2, islemTipi, sonucBoyut);
	//print sonucMatrix as an output
	printf("sonucMatrix %dx%d: ", sonucBoyut-1, sonucBoyut-1);
	printMatrix(sonucMatrix, sonucBoyut-1);
	
    // free allocated memories for matrices
	freeMatrix(matrix1, size1);
	puts("matrix1 is freed \n");

	freeMatrix(matrix2, size2);
	puts("matrix2 is freed \n");

	freeMatrix(sonucMatrix, sonucBoyut);
	puts("sonucMatrix is freed \n");

	puts("\nAll matrices have been freed\n");
	puts("Pres any key to end program...");
	getch();
	puts("\n********* PROGRAM ENDED *********\n");
    return 0;
}