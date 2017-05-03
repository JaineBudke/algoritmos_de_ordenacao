#include <iostream>
#include "ordenacao.h" 

int main(){
     
    int tam = 7;

    ////////////// INSERTIONSORT ///////////////////
    int A[] = { 10, 99, 82, 83, 84, 19, 29 };
    std::cout << "INSERTIONSORT - Vetor normal = [ ";
    for (int i = 0; i < tam; ++i ) {
        std::cout << A[i] << " ";
    }
    std::cout << "]\n";
    insertionSort( A, tam );
    std::cout << "INSERTIONSORT - Vetor ordenado = [ ";
    for (int i = 0; i < tam; ++i ) {
        std::cout << A[i] << " ";
    }
    std::cout << "]\n";

    ////////////// SELECTIONSORT ///////////////////
    int B[] = { 10, 99, 82, 83, 84, 19, 29 };
    std::cout << "SELECTIONSORT - Vetor normal = [ ";
    for (int i = 0; i < tam; ++i ) {
        std::cout << B[i] << " ";
    }
    std::cout << "]\n";
    selectionSort( B, tam );
    std::cout << "SELECTIONSORT - Vetor ordenado = [ ";
    for (int i = 0; i < tam; ++i ) {
        std::cout << B[i] << " ";
    }
    std::cout << "]\n";

    ////////////// QUICKSORT ///////////////////
    int V[] = { 10, 99, 82, 83, 84, 19, 29 };
    std::cout << "QUICKSORT - Vetor normal = [ ";
    for (int i = 0; i < tam; ++i ) {
        std::cout << V[i] << " ";
    }
    std::cout << "]\n";
    quickSort( V, 0, tam-1 );
    std::cout << "QUICKSORT - Vetor ordenado = [ ";
    for (int i = 0; i < tam; ++i ) {
        std::cout << V[i] << " ";
    }
    std::cout << "]\n";

    /////////////// MERGESORT //////////////////
    int C[] = { 10, 99, 82, 83, 84, 19, 29 };
    std::cout << "MERGESORT - Vetor normal = [ ";
    for (int i = 0; i < tam; ++i ) {
        std::cout << C[i] << " ";
    }
    std::cout << "]\n";
    mergesort(C, 0, tam-1);    
    std::cout << "MERGESORT - Vetor ordenado = [ ";
    for (int i = 0; i < tam; ++i ) {
        std::cout << C[i] << " ";
    }
    std::cout << "]\n";

 
    return 0;

}
 
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