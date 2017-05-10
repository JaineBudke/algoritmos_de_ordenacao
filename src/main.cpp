/**
 * @file    main.cpp
 * @brief   Código fonte do prgrama com medição de tempo de execução dos algoritmos de busca
 * @author  Bianca Santiago (bianca.santiago72@gmail.com)
 * @author  Jaine Budke (jainebudke@hotmail.com)
 * @since   18/04/2017
 * @date    22/05/2017
 */

#include "manager.h"
#include "ordenacao.h"

#include <time.h>
#include <ctime>

/**
*@brief Função principal que contém o tempo de execução dos algoritmos de busca.
*/
int main(){

    std::srand(std::time(0)); // semente do rand

    // declara os diferentes tamanhos de base de busca que serão analisados
    int tamBase[] = { 1000, 5000, 10000, 15000, 50000, 100000, 500000, 600000, 700000, 800000, 900000, 1000000 };


    for( int i = 0 ; i <  4; ++i ){
        std::cout << "===========================\n";
        std::cout << "Tamanho de busca = " << tamBase[i] << "\n";
        std::cout << "===========================\n";

        // RESULTADO COM ORDENACAO InsertionSort
        std::cout << "InsertionSort: \n";
        std::function < void( int*, int ) >insertion = insertionSort;
        analiseCasos( tamBase[i], insertion );
        std::cout << "\n";

        // RESULTADO COM ORDENACAO SelectionSort
        std::cout << "SelectionSort: \n";
        std::function < void( int*, int ) >selection = selectionSort;
        analiseCasos( tamBase[i], selection );
        std::cout << "\n";
    }


    for( int i = 0 ; i <  12; ++i ){
        std::cout << "===========================\n";
        std::cout << "Tamanho de busca = " << tamBase[i] << "\n";
        std::cout << "===========================\n";

        // RESULTADO COM ORDENACAO QuickSort
        std::cout << "QuickSort: \n";
        std::function < int( int*, int, int ) >quick = quickSort;
        analiseCasos2( tamBase[i], quick );
        std::cout << "\n";

        // RESULTADO COM ORDENACAO mergeSort
        std::cout << "MergeSort: \n";
        std::function < int( int*, int, int ) >merge = mergesort;
        analiseCasos2( tamBase[i], merge );
        std::cout << "\n";

    }

    return 0;

}