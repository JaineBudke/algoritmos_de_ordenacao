#include <iostream>
#include "ordenacao.h" 


int insertionSort( int *V, int tam ){
 
    for( int i=1; i<tam; i++ ){
 
        int elem = V[i];
        int j = i-1;
 
        while( (j>=0) && (V[j] > elem) ){
            V[j+1] = V[j];
            j--;
        }
 
        V[j+1] = elem;
 
    }
 
}

int selectionSort( int *V, int tam ){
 
    for( int i=0 ; i < tam ; i++ ){
 
        int menor = V[i];
        int indiceMenor = i;
 
        for( int j=i+1 ; j<tam ; j++ ){
 
            if( V[j] < menor ){
                menor = V[j];
                indiceMenor = j;
            }
 
        }
 
        std::swap( V[i], V[indiceMenor] );
 
    }
 
}
 
int quickSort( int *V, int inicio, int fim ){
 
    if( fim < inicio ) return 0;
 
    int pp = inicio+1;
    int qq = fim;
 
    while( pp < qq ){
 
        while( V[pp] <= V[inicio] && pp < qq ) pp++;
        while( V[qq] > V[inicio] ) qq--;
        if( pp < qq ){
            std::swap( V[pp], V[qq] );
        }
 
    }
 
    std::swap( V[qq], V[inicio] );
    quickSort( V, inicio, qq-1 );
    quickSort( V, qq+1, fim );
}

void mergesort(int *V, int inicio, int fim) {

    int mid;
    if (inicio < fim) {

        mid=(inicio+fim)/2;
        mergesort(V,inicio,mid);
        mergesort(V,mid+1,fim);
        merge(V,inicio,fim,mid);

    }

    return;

}

void merge( int *V, int inicio, int fim, int mid ) {

    int i, j, k, C[50];
    i = inicio;
    k = inicio;
    j = mid + 1;

    while (i <= mid && j <= fim) {

        if (V[i] < V[j]) {
            C[k] = V[i];
            k++;
            i++;
        }

        else {
            C[k] = V[j];
            k++;
            j++;
        }

    }

    while (i <= mid) {
        C[k] = V[i];
        k++;
        i++;
    }

    while (j <= fim){
        C[k] = V[j];
        k++;
        j++;
    }

    for (i = inicio; i < k; i++){
        V[i] = C[i];
    }

}