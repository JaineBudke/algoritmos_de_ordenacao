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

/**
 * @brief Auxilia na ordenacao do mergeSort. Junta os fragmentos de ordenacao.
 * @details Algoritmo implementado de maneira iterativa.
 * @param V Vetor com a base de busca.
 * @param inicio Posicao/indice inicial do vetor.
 * @param fim Posicao/indice final do vetor.
 * @param mid Posicao/indice da metade do vetor.
 */
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