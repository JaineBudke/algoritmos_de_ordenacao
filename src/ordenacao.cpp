/**
 * @file    ordenacao.cpp
 * @brief   Código fonte com a implementacao de funcoes que
            realizam a ordenacao de um vetor de inteiros, de
            tamanho n, passado por parametro.
 * @author  Bianca Santiago (bianca.santiago72@gmail.com)
 * @author  Jaine Budke (jainebudke@hotmail.com)
 * @since   18/04/2017
 * @date    22/05/2017
 */

#include "ordenacao.h"
#include <time.h>
#include <chrono>
#include <ctime>

/**
 * @brief Realiza a ordenacao em uma base de dados, passada por
          parametro por meio de um vetor, de tamanho n.
 * @details Algoritmo de ordenacao implementado de maneira iterativa e com o metodo insertionSort.
 * @param V Vetor com a base de busca.
 * @param n Tamanho do vetor.
 */

void insertionSort( int *V, int n ){

    for( int i=1; i<n; i++ ){

        int elem = V[i];
        int j = i-1;

        while( (j>=0) && (V[j] > elem) ){
            V[j+1] = V[j];
            j--;
        }

        V[j+1] = elem;

    }

}

/**
 * @brief Realiza a ordenacao em uma base de dados, passada por
          parametro por meio de um vetor, de tamanho n.
 * @details Algoritmo de ordenacao implementado de maneira iterativa e com o metodo selectionSort.
 * @param V Vetor com a base de busca.
 * @param n Tamanho do vetor.
 */
void selectionSort( int *V, int n ){

    for( int i=0 ; i < n ; i++ ){

        int menor = V[i];
        int indiceMenor = i;

        for( int j=i+1 ; j<n ; j++ ){

            if( V[j] < menor ){
                menor = V[j];
                indiceMenor = j;
            }

        }

        std::swap( V[i], V[indiceMenor] );

    }

}

/**
 * @brief Realiza a ordenacao em uma base de dados, passada por
          parametro por meio de um vetor, de tamanho n.
 * @details Algoritmo de ordenacao implementado de maneira recursiva e com o metodo quickSort.
 * @param V Vetor com a base de busca.
 * @param inicio Posicao/indice inicial do vetor.
 * @param fim Posicao/indice final do vetor.
 * @return 1 se ordenado, 0 caso contrário.
 */
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


/**
 * @brief Realiza a ordenacao em uma base de dados, passada por
          parametro por meio de um vetor, de tamanho n.
 * @details Algoritmo de ordenacao implementado de maneira recursiva e com o metodo mergesort.
 * @param V Vetor com a base de busca.
 * @param inicio Posicao/indice inicial do vetor.
 * @param fim Posicao/indice final do vetor.
 */
int mergesort( int*V, int inicio, int fim ) {

    if( fim>inicio ) {
        int q;
        q=(inicio+fim)/2;
        mergesort( V, inicio, q );
        mergesort( V, q+1, fim );
        merge( V, inicio, q, fim );
    }

    return 1;

}

/**
 * @brief Auxilia na ordenacao do mergeSort. Junta os fragmentos de ordenacao.
 * @details Algoritmo implementado de maneira iterativa.
 * @param V Vetor com a base de busca.
 * @param inicio Posicao/indice inicial do vetor.
 * @param fim Posicao/indice final do vetor.
 * @param mid Posicao/indice da metade do vetor.
 */
void merge( int* V, int inicio, int fim, int mid ) {

    int n1=fim-inicio+1;
    int n2=mid-fim;

    int L[n1+1];
    int R[n2+1];

    for(int i=0; i<n1; i++)
        L[i]=V[inicio+i];
    for(int j=0; j<n2; j++)
        R[j]=V[fim+1+j];

    int i=0;
    int j=0;
    int n=0;

    while( i != n1 && j != n2 ) {

        if( L[i] > R[j] ) {
            V[inicio+n] = R[j];
            j++;
        } else {
            V[inicio+n] = L[i];
            i++;
        }
        n++;
    }
    while( j != n2 ) {
        V[inicio+n] = R[j];
        j++;
        n++;
    }
    while( i != n1 ) {
        V[inicio+n]=L[i];
        i++;
        n++;
    }

}