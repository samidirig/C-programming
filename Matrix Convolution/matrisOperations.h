/*
* @file matrisoperations.h
* @description initializing function prototypes.
* @assignment Bp3 Proje 1
* @date 16.02.2021
* @author Mahmudhan Sami Diriğ ve mahmudhansami.dirig@stu.fsm.edu.tr
*/
#ifndef matrisOperations
#define matrisOperations

int** operasyon1(int** matrix1, int** matrix2, int islemTipi, int size);
void matrixDoldur(int **matrix, int boyut, int seed);	
void matrixKenarliDoldur(int **matrix, int boyut, int seed, int dSize);
void printMatrix(int** matrix, int size);	
int** allocateMatrix(int size);	
void freeMatrix(int **matrix, int size);	
int findDtype(int islemTipi, int fSize);	
int size1, size2, sonucBoyut,islemTipi,seed;


#endif
