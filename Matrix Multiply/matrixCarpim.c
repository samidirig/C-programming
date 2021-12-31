#include <stdio.h>
#include <stdlib.h>
#include "time.h"
#include <conio.h>
void matrixDoldur(float **matrix, int size);
void freeMatrix(float **matrix, int size);
void matrixMatrixMultiplyijk(float **matrix1, float **matrix2, float **resultMatrix, int size);
void matrixMatrixMultiplyikj(float **matrix1, float **matrix2, float **resultMatrix, int size);
void matrixMatrixMultiplyjik(float **matrix1, float **matrix2, float **resultMatrix, int size);
void matrixMatrixMultiplyjki(float **matrix1, float **matrix2, float **resultMatrix, int size);
void matrixMatrixMultiplykij(float **matrix1, float **matrix2, float **resultMatrix, int size);
void matrixMatrixMultiplykji(float **matrix1, float **matrix2, float **resultMatrix, int size);

int main(){
	int i;
	int size;
	printf("Enter Size: ");
	scanf("%d", &size);
	
	float **matrix1;
	float **matrix2;
	float **resultMatrix;
	matrix1 = (float **) malloc (size * sizeof(float*));
	if (matrix1 == NULL)
		printf( "There isn't enough space on memory. matrix1 \n");
	
	matrix2 = (float **) malloc (size * sizeof(float*));
	if (matrix2 == NULL)
		printf( "There isn't enough space on memory. matrix2 \n");

	resultMatrix = (float**) malloc (size * sizeof(float*));			
	if (resultMatrix == NULL)
		printf( "There isn't enough space on memory. resultMatrix \n");
	
	for(i=0; i<size; i++)	{							
		matrix1[i] = (float*) malloc ( size * sizeof(float));
		if (matrix1[i]== NULL)
			printf( "There isn't enough space on memory. %d \n", i);
	
		matrix2[i] = (float*) malloc ( size * sizeof(float));
		if (matrix2[i]== NULL)
			printf( "There isn't enough space on memory. %d \n", i);
	
		resultMatrix[i] = (float*) malloc ( size * sizeof(float));
		if (resultMatrix[i]== NULL)
			printf( "There isn't enough space on memory. %d \n", i);
	}
	matrixDoldur(matrix1,size);
	matrixDoldur(matrix2,size);

	matrixMatrixMultiplyijk(matrix1, matrix2, resultMatrix, size);
	matrixMatrixMultiplyikj(matrix1, matrix2, resultMatrix, size);
	matrixMatrixMultiplyjik(matrix1, matrix2, resultMatrix, size);
	matrixMatrixMultiplykij(matrix1, matrix2, resultMatrix, size);
	matrixMatrixMultiplyjki(matrix1, matrix2, resultMatrix, size);
	matrixMatrixMultiplykji(matrix1, matrix2, resultMatrix, size);
	
	freeMatrix(matrix1, size);
	freeMatrix(matrix2, size);
	freeMatrix(resultMatrix, size);
	
	puts("\nAll matrices have been freed\n");
	puts("Pres any key to end program...");
	getch();
	puts("\n********* PROGRAM ENDED *********\n");
	return 0;
}

void matrixDoldur(float **matrix, int size){
	int i,j;
	float random;	
	srand(time(0));
	for(i=0; i<size; i++){
		for(j=0; j<size; j++){
			random = rand()%5+1;
			matrix[i][j]=random;
		}
	}printf("Function matrixDoldur has worked.\n");
}
void freeMatrix(float **matrix, int size){
    int i = 0;
    for(i = 0; i < size; i++){
        free(matrix[i]);
    }
    free(matrix);
}
void matrixMatrixMultiplyijk(float **matrix1, float **matrix2, float **resultMatrix, int size){
	int i,j,k;
	clock_t t;
	t=clock();	
	for (i = 0; i < size; i++){
		for (j = 0; j < size; j++){
			for(k = 0; k < size; k++){
				resultMatrix[i][j]+=matrix1[i][k]*matrix2[k][j];	
			}
		}		
	}
	printf("\n i j k Multiply has done..");
	t=clock()-t;	
	double time_taken = ((double) t)/CLOCKS_PER_SEC;
	printf("  The passed time for %d size Multiply: %f\n",size, time_taken);
}

void matrixMatrixMultiplyikj(float **matrix1, float **matrix2, float **resultMatrix, int size){
	int i,j,k;
	clock_t t;
	t=clock();	
	for (i = 0; i < size; i++){
		for (k = 0; k < size; k++){
			for(j = 0; j < size; j++){
				resultMatrix[i][j]+=matrix1[i][k]*matrix2[k][j];	
			}
		}			
	}
	printf("\n i k j Multiply has done..");
	t=clock()-t;	
	double time_taken = ((double) t)/CLOCKS_PER_SEC;
	printf("  The passed time for %d size Multiply: %f\n",size, time_taken);	
}

void matrixMatrixMultiplyjik(float **matrix1, float **matrix2, float **resultMatrix, int size){
	int i,j,k;	
	clock_t t;
	t=clock();
	for (j = 0; j < size; j++){
		for (i = 0; i < size; i++){
			for(k = 0; k < size; k++){
				resultMatrix[i][j]+=matrix1[i][k]*matrix2[k][j];	
			}
		}			
	}
	printf("\n j i k Multiply has done..");
	t=clock()-t;	
	double time_taken = ((double) t)/CLOCKS_PER_SEC;
	printf("  The passed time for %d size Multiply: %f\n",size, time_taken);	
}

void matrixMatrixMultiplyjki(float **matrix1, float **matrix2, float **resultMatrix, int size){
	int i,j,k;	
	clock_t t;
	t=clock();
	for (j = 0; j < size; j++){
		for (k = 0; k < size; k++){
			for(i = 0; i < size; i++){
				resultMatrix[i][j]+=matrix1[i][k]*matrix2[k][j];	
			}
		}			
	}
	printf("\n j k i Multiply has done..");	
	t=clock()-t;	
	double time_taken = ((double) t)/CLOCKS_PER_SEC;
	printf("  The passed time for %d size Multiply: %f\n",size, time_taken);	
}

void matrixMatrixMultiplykij(float **matrix1, float **matrix2, float **resultMatrix, int size){
	int i,j,k;	
	clock_t t;
	t=clock();
	for (k = 0; k < size; k++){
		for (i = 0; i < size; i++){
			for(j = 0; j < size; j++){
				resultMatrix[i][j]+=matrix1[i][k]*matrix2[k][j];	
			}
		}			
	}
	printf("\n k i j Multiply has done..");	
	t=clock()-t;	
	double time_taken = ((double) t)/CLOCKS_PER_SEC;
	printf("  The passed time for %d size Multiply: %f\n",size, time_taken);	
}

void matrixMatrixMultiplykji(float **matrix1, float **matrix2, float **resultMatrix, int size){
	int i,j,k;	
	clock_t t;
	t=clock();
	for (k = 0; k < size; k++){
		for (j = 0; j < size; j++){
			for(i = 0; i < size; i++){
				resultMatrix[i][j]+=matrix1[i][k]*matrix2[k][j];	
			}
		}
	}
	printf("\n k j i Multiply has done..");	
	t=clock()-t;	
	double time_taken = ((double) t)/CLOCKS_PER_SEC;
	printf("  The passed time for %d size Multiply: %f\n",size, time_taken);	
}



	
