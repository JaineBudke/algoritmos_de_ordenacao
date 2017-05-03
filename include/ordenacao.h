#ifndef _ORDENACAO_H_
#define _ORDENACAO_H_

int quickSort( int *V, int inicio, int fim );
void merge( int *V, int inicio, int fim, int mid );
void mergesort( int *V, int inicio, int fim );
int insertionSort( int *V, int tam );
int selectionSort( int *V, int tam );

#endif