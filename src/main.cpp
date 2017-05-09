/**
 * @file    main.cpp
 * @brief   Código fonte do prgrama com medição de tempo de execução dos algoritmos de busca
 * @author  Bianca Santiago (bianca.santiago72@gmail.com)
 * @author  Jaine Budke (jainebudke@hotmail.com)
 * @since   18/04/2017
 * @date    22/05/2017
 */

#include "manager.h"
#include <time.h>
#include <ctime>
/**
*@brief Função principal que contém o tempo de execução dos algoritmos de busca.
*/
int main(){

    std::srand(std::time(0)); // semente do rand

    // declara os diferentes tamanhos de base de busca que serão analisados
    int tamBase[] = { 10000, 50000, 100000, 1000000 };

    for( int i = 0 ; i <  4; ++i ){
        std::cout << "===========================\n";
        std::cout << "Tamanho de busca = " << tamBase[i] << "\n";
        std::cout << "===========================\n";
        std::cout << "InsertionSort: \n";
        analiseCasosIS( tamBase[i] );
        std::cout << "\n";
        std::cout << "SelectionSort: \n";
        analiseCasosSS( tamBase[i] );
        std::cout << "\n";
    }




    return 0;

}
