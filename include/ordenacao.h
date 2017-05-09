/**
 * @file    ordenacao.h
 * @brief   Arquivo cabeçalho com a implementacao de funcoes que
                 realizam a ordenacao de uma base de dados, passada por
                 parametro por meio de um vetor, de tamanho n.
 * @author  Bianca Santiago (bianca.santiago72@gmail.com)
 * @author  Jaine Budke (jainebudke@hotmail.com)
 * @since   18/04/2017
 * @date    22/05/2017
 */

#ifndef _ORDENACAO_H_
#define _ORDENACAO_H_


#include <iostream>


/**
 * @brief Realiza a ordenacao em uma base de dados, passada por
          parametro por meio de um vetor, de tamanho n.
 * @details Algoritmo de ordenacao implementado de maneira iterativa e com o metodo insertionSort.
 * @param V Vetor com a base de busca.
 * @param n Tamanho do vetor.
 */
void insertionSort( int *V, int n );


/**
 * @brief Realiza a ordenacao em uma base de dados, passada por
          parametro por meio de um vetor, de tamanho n.
 * @details Algoritmo de ordenacao implementado de maneira iterativa e com o metodo selectionSort.
 * @param V Vetor com a base de busca.
 * @param n Tamanho do vetor.
 */
void selectionSort( int *V, int n );


/**
 * @brief Realiza a ordenacao em uma base de dados, passada por
          parametro por meio de um vetor, de tamanho n.
 * @details Algoritmo de ordenacao implementado de maneira recursiva e com o metodo quickSort.
 * @param V Vetor com a base de busca.
 * @param inicio Posicao/indice inicial do vetor.
 * @param fim Posicao/indice final do vetor.
 * @return 1 se ordenado, 0 caso contrário.
 */
int quickSort( int *V, int inicio, int fim );


/**
 * @brief Realiza a ordenacao em uma base de dados, passada por
          parametro por meio de um vetor, de tamanho n.
 * @details Algoritmo de ordenacao implementado de maneira recursiva e com o metodo mergesort.
 * @param V Vetor com a base de busca.
 * @param inicio Posicao/indice inicial do vetor.
 * @param fim Posicao/indice final do vetor.
 */
void mergesort( int *V, int inicio, int fim );


/**
 * @brief Auxilia na ordenacao do mergeSort. Junta os fragmentos de ordenacao.
 * @details Algoritmo implementado de maneira iterativa.
 * @param V Vetor com a base de busca.
 * @param inicio Posicao/indice inicial do vetor.
 * @param fim Posicao/indice final do vetor.
 * @param mid Posicao/indice da metade do vetor.
 */
void merge( int *V, int inicio, int fim, int mid );



#endif