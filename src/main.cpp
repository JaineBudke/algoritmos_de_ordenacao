/**
 * @file    main.cpp
 * @brief   Código fonte do prgrama com medição de tempo de execução dos algoritmos de busca
 * @author  Bianca Santiago (bianca.santiago72@gmail.com)
 * @author  Jaine Budke (jainebudke@hotmail.com)
 * @since   18/04/2017
 * @date    22/05/2017
 */

#include "ordenacao.h"

/**
*@brief Função principal que contém o tempo de execução dos algoritmos de busca.
*/
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