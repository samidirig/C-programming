
/*
* @file matrisoperations.c
* @description initialization of functions over the given matrices to add and multiply the elements with each other.
* @date 16.12.2021
* @author Mahmudhan Sami Diriğ ve mahmudhansami.dirig@stu.fsm.edu.tr
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "time.h"
#include "matrisOperations.h"

//method to find D size for the sonucMatrix size
int findDtype(int islemTipi, int fSize){
	int dSize=0;
	if (islemTipi == 0){
		return dSize;
	}else if (islemTipi == 1){
		dSize = (fSize-1)/2;
	}
	return dSize;
}
//filling matrices if the islemTipi is '0' to processing 
void matrixDoldur(int **matrix, int boyut, int seed){
	int i,j;
	int random;	
	srand(seed);
	for(i=0; i<boyut; i++){
		for(j=0; j<boyut; j++){
			random = rand()%9+1;
			matrix[i][j]=random;
		}
	}
}//filling matrices if the islemTipi is '1' to processing
void matrixKenarliDoldur(int **matrix, int boyut, int seed, int dSize){
	int i,j;
	int random;	
	srand(seed);
	//control dSize and filling given matrix with 0 up to the padding(dolgu) value.
	if (dSize == 1){
		for ( i = 0; i < boyut; i++){
    		for ( j = 0; j < boyut; j++){
    	    	if(i == 0 || j == 0){
    	        	matrix[i][j]=0;
    	    	}else if((i+1) == boyut-dSize || (j+1) == boyut-dSize){
    	        	matrix[i][j]=0;
    	    	}else{
					random = rand()%9+1;
					matrix[i][j]=random;
				}
    		}
    	}
	}else if (dSize ==  2){
		for ( i = 0; i < boyut; i++){
    		for ( j = 0; j < boyut; j++){
    	    	if(i == 0 || i == 1 || j == 0 || j == 1){
    	        	matrix[i][j]=0;
    	    	}else if((i+1) == boyut-(dSize-1) || (j+1) == boyut-(dSize-1) 
							|| (i+3) == boyut-(dSize-2) || (j+3) == boyut-(dSize-2)){
    	        	matrix[i][j]=0;
    	    	}else{
					random = rand()%9+1;
					matrix[i][j]=random;
				}
    		}
    	}
	}
	
	

}
//method to print given matrix
void printMatrix(int** matrix, int size){
	int i,j;
	
	for( i=0; i<size; i++ ){
		printf("\n");
		for( j=0; j<size; j++ ){
			printf("%d  ", matrix[i][j]);
		}
	}printf("\n\n");
}
//method to allocate memory for given matrix.
int** allocateMatrix(int size){
	int i = 0;
	int **matrixPtr = (int **) malloc(sizeof(int*)*size);
	if (matrixPtr == NULL)
		puts( "Bellekte yeterli alan yok. matrix1 \n");
	for( i=0; i<size; i++ ){
		matrixPtr[i] = (int*)malloc( size * sizeof(int) );
		if( matrixPtr[i] == NULL)
		printf( "Bellekte yeterli alan yok. %d \n", i);
	}
	return matrixPtr;
}
//method to reallocate memory for given matrix
void freeMatrix(int **matrix, int size){
    int i = 0;
    for(i = 0; i < size; i++){
        free(matrix[i]);
    }
    free(matrix);
}
// doing operation with matrix1 and matrix2 and returning the conclusion matrix
int** operasyon1(int** matrix1, int** matrix2, int islemTipi, int size){
	int **result;
	size++;	
	result = allocateMatrix(size);
	puts("sonucMatrix allocated \n");
	int i,j,k,m;
	int toplam, kaydirX, kaydirY=0;
	
	if (islemTipi == 0){
		// birinci resimdeki matrislerin işlemleri (islemtipi is '0'. we have dSize=0. so the control processing like in img1)
		for ( k = 0; k < (size - 2); k++){
            for ( i = 0; i < (size - 2); i++){
                kaydirX = k;
                for ( m = 0; m < 3; m++){
                    for ( j = 0; j < 3; j++){
                        toplam += matrix1[kaydirX+m][j+kaydirY] * matrix2[m][j];
                    }  
                }
                result[k][i] = toplam;
				//sonucMatrix[k][i] = toplam;
                toplam = 0;  
                kaydirY++;
            }kaydirX++;
            kaydirY = 0; 
        }
	}else if (islemTipi == 1){
		// ikinci resimdeki matrixte 0 bulunan işlemler (islemtipi is '1'. we have dSize. so the control processing like in img2)
		for ( k = 0; k < (size - 2); k++){
            for ( i = 0; i < (size - 2); i++){
                kaydirX = k;
                for ( m = 0; m < 3; m++){
                    for ( j = 0; j < 3; j++){
                        toplam += matrix1[kaydirX+m][j+kaydirY] * matrix2[m][j];
                    }  
                }
                result[k][i] = toplam;
				//sonucMatrix[k][i] = toplam;
                toplam = 0;  
                kaydirY++;
            }kaydirX++;
            kaydirY = 0; 
        }
	}
	
    return result;    
}
