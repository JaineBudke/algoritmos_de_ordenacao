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

#include <iomanip>
using std::setw;

#include <fstream>
using std::ofstream;

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




///////////////////////////////////////////////////////////////////////////
    // GRAVANDO DADOS EM ARQUIVOS dadosInsertionSortMelhor.txt, dadosInsertionSortPior.txt, dadosInsertionSortMedio.txt
    ///////////////////////////////////////////////////////////////////////////
    // Gravando em dadosInsertionSortMelhor.txt
    std::ofstream arqsaidaInsertionSortMelhor;
    arqsaidaInsertionSortMelhor.open( "dadosInsertionSortMelhor.txt", std::ios::out );
    if( !arqsaidaInsertionSortMelhor.is_open() ){
        return 0;
    }

    std::cout << "Gerando dados InsertionSortMelhor..." << std::endl;

    // Grava o cabeçalho
    arqsaidaInsertionSortMelhor << "#Dados para o script geraGrafico.gnu do InsertionSortMelhor" << std::endl;
    /*
     * X - Tamanho da base de busca
     * Y - Tempo de execução
     * W - Chave de busca
    */
    arqsaidaInsertionSortMelhor << "#X" << std::setw(10) << "#Y" << std::endl;

    // Gravando em dadosInsertionSortPior.txt
    std::ofstream arqsaidaInsertionSortPior;
    arqsaidaInsertionSortPior.open( "dadosInsertionSortPior.txt", std::ios::out );
    if( !arqsaidaInsertionSortPior.is_open() ){
        return 0;
    }

    std::cout << "Gerando dados InsertionSortPior..." << std::endl;

    // Grava o cabeçalho
    arqsaidaInsertionSortPior << "#Dados para o script geraGrafico.gnu do InsertionSortPior" << std::endl;
    /*
     * X - Tamanho da base de busca
     * Y - Tempo de execução
     * W - Chave de busca
    */
    arqsaidaInsertionSortPior << "#X" << std::setw(10) << "#Y" << std::endl;

    // Gravando em dadosInsertionSortMedio.txt
    std::ofstream arqsaidaInsertionSortMedio;
    arqsaidaInsertionSortMedio.open( "dadosInsertionSortMedio.txt", std::ios::out );
    if( !arqsaidaInsertionSortMedio.is_open() ){
        return 0;
    }

    std::cout << "Gerando dados InsertionSortMedio..." << std::endl;

    // Grava o cabeçalho
    arqsaidaInsertionSortMedio << "#Dados para o script geraGrafico.gnu do InsertionSortMedio" << std::endl;
    /*
     * X - Tamanho da base de busca
     * Y - Tempo de execução
     * W - Chave de busca
    */
    arqsaidaInsertionSortMedio << "#X" << std::setw(10) << "#Y" << std::endl;


    ///////////////////////////////////////////////////////////////////////////
    // GRAVANDO DADOS EM ARQUIVOS dadosSelectionSortMelhor.txt, dadosSelectionSortPior.txt, dadosSelectionSortMedio.txt
    ///////////////////////////////////////////////////////////////////////////
    // Gravando dadosSelectionSortMelhor.txt
    std::ofstream arqsaidaSelectionSortMelhor;
    arqsaidaSelectionSortMelhor.open( "dadosSelectionSortMelhor.txt", std::ios::out );
    if( !arqsaidaSelectionSortMelhor.is_open() ){
        return 0;
    }

    std::cout << "Gerando dados SelectionSortMelhor..." << std::endl;

    // Grava o cabeçalho
    arqsaidaSelectionSortMelhor << "#Dados para o script geraGrafico.gnu do SelectionSortMelhor" << std::endl;
    /*
     * X - Tamanho da base de busca
     * Y - Tempo de execução
     * W - Chave de busca
    */
    arqsaidaSelectionSortMelhor << "#X" << std::setw(10) << "#Y" << std::endl;

    // Gravando dadosSelectionSortPior.txt
    std::ofstream arqsaidaSelectionSortPior;
    arqsaidaSelectionSortPior.open( "dadosBR2.txt", std::ios::out );
    if( !arqsaidaSelectionSortPior.is_open() ){
        return 0;
    }

    std::cout << "Gerando dados SelectionSortPior..." << std::endl;

    // Grava o cabeçalho
    arqsaidaSelectionSortPior << "#Dados para o script geraGrafico.gnu do SelectionSortPior" << std::endl;
    /*
     * X - Tamanho da base de busca
     * Y - Tempo de execução
     * W - Chave de busca
    */
    arqsaidaSelectionSortPior << "#X" << std::setw(10) << "#Y" << std::endl;

    // Gravando dadosSelectionSortMedio.txt
    std::ofstream arqsaidaSelectionSortMedio;
    arqsaidaSelectionSortMedio.open( "dadosSelectionSortMedio.txt", std::ios::out );
    if( !arqsaidaSelectionSortMedio.is_open() ){
        return 0;
    }

    std::cout << "Gerando dados SelectionSortMedio..." << std::endl;

    // Grava o cabeçalho
    arqsaidaSelectionSortMedio << "#Dados para o script geraGrafico.gnu do SelectionSortMedio" << std::endl;
    /*
     * X - Tamanho da base de busca
     * Y - Tempo de execução
     * W - Chave de busca
    */
    arqsaidaSelectionSortMedio << "#X" << std::setw(10) << "#Y" << std::endl;


    ///////////////////////////////////////////////////////////////////////////
    // GRAVANDO DADOS EM ARQUIVOS dadosQuickSortMelhor.txt, dadosQuickSortPior.txt, dadosQuickSortMedio.txt
    ///////////////////////////////////////////////////////////////////////////
    // Gravando dadosQuickSortMelhor.txt
    std::ofstream arqsaidaQuickSortMelhor;
    arqsaidaQuickSortMelhor.open( "dadosQuickSortMelhor.txt", std::ios::out );
    if( !arqsaidaQuickSortMelhor.is_open() ){
        return 0;
    }

    std::cout << "Gerando dados QuickSortMelhor..." << std::endl;

    // Grava o cabeçalho
    arqsaidaQuickSortMelhor << "#Dados para o script geraGrafico.gnu do QuickSortMelhor" << std::endl;
    /*
     * X - Tamanho da base de busca
     * Y - Tempo de execução
     * W - Chave de busca
    */
    arqsaidaQuickSortMelhor << "#X" << std::setw(10) << "#Y" << std::endl;

    // Gravando dadosQuickSortPior.txt
    std::ofstream arqsaidaQuickSortPior;
    arqsaidaQuickSortPior.open( "dadosQuickSortPior.txt", std::ios::out );
    if( !arqsaidaQuickSortPior.is_open() ){
        return 0;
    }

    std::cout << "Gerando dados QuickSortPior..." << std::endl;

    // Grava o cabeçalho
    arqsaidaQuickSortPior << "#Dados para o script geraGrafico.gnu do QuickSortPior" << std::endl;
    /*
     * X - Tamanho da base de busca
     * Y - Tempo de execução
     * W - Chave de busca
    */
    arqsaidaQuickSortPior << "#X" << std::setw(10) << "#Y" << std::endl;

    // Gravando dadosQuickSortMedio.txt
    std::ofstream arqsaidaQuickSortMedio;
    arqsaidaQuickSortMedio.open( "dadosQuickSortMedio.txt", std::ios::out );
    if( !arqsaidaQuickSortMedio.is_open() ){
        return 0;
    }

    std::cout << "Gerando dados QuickSortMedio..." << std::endl;

    // Grava o cabeçalho
    arqsaidaQuickSortMedio << "#Dados para o script geraGrafico.gnu do QuickSortMedio" << std::endl;
    /*
     * X - Tamanho da base de busca
     * Y - Tempo de execução
     * W - Chave de busca
    */
    arqsaidaQuickSortMedio << "#X" << std::setw(10) << "#Y" << std::endl;


        ///////////////////////////////////////////////////////////////////////////
    // GRAVANDO DADOS EM ARQUIVOS dadosMergeSortMelhor.txt, dadosMergeSortPior.txt, dadosMergeSortMedio.txt
    ///////////////////////////////////////////////////////////////////////////
    // Gravando dadosMergeSortMelhor.txt
    std::ofstream arqsaidaMergeSortMelhor;
    arqsaidaMergeSortMelhor.open( "dadosMergeSortMelhor.txt", std::ios::out );
    if( !arqsaidaMergeSortMelhor.is_open() ){
        return 0;
    }

    std::cout << "Gerando dados MergeSortMelhor..." << std::endl;

    // Grava o cabeçalho
    arqsaidaSelectionSortMelhor << "#Dados para o script geraGrafico.gnu  do MergeSortMelhor" << std::endl;
    /*
     * X - Tamanho da base de busca
     * Y - Tempo de execução
     * W - Chave de busca
    */
    arqsaidaMergeSortMelhor << "#X" << std::setw(10) << "#Y" << std::endl;

    // Gravando dadosMergeSortPior.txt
    std::ofstream arqsaidaMergeSortPior;
    arqsaidaMergeSortPior.open( "dadosMergeSortPior.txt", std::ios::out );
    if( !arqsaidaMergeSortPior.is_open() ){
        return 0;
    }

    std::cout << "Gerando dados MergeSortPior..." << std::endl;

    // Grava o cabeçalho
    arqsaidaMergeSortPior << "#Dados para o script geraGrafico.gnu  do MergeSortPior" << std::endl;
    /*
     * X - Tamanho da base de busca
     * Y - Tempo de execução
     * W - Chave de busca
    */
    arqsaidaMergeSortPior << "#X" << std::setw(10) << "#Y" << std::endl;

    // Gravando dadosMergeSortMedio.txt
    std::ofstream arqsaidaMergeSortMedio;
    arqsaidaMergeSortMedio.open( "dadosMergeSortMedio.txt", std::ios::out );
    if( !arqsaidaMergeSortMedio.is_open() ){
        return 0;
    }

    std::cout << "Gerando dados MergeSortMedio..." << std::endl;

    // Grava o cabeçalho
    arqsaidaMergeSortMedio << "#Dados para o script geraGrafico.gnu  do MergeSortMedio" << std::endl;
    /*
     * X - Tamanho da base de busca
     * Y - Tempo de execução
     * W - Chave de busca
    */
    arqsaidaMergeSortMedio << "#X" << std::setw(10) << "#Y" << std::endl;



    for ( int i = 0 ; i < nBases ; ++i ) { // Fazendo várias buscas, com bases aleatórias de diferentes tamanhos

        int tamBase = tamN[i]; // Tamanho da base de busca
        int base[ tamBase ];   // Vetor com os valores da base

        generateRandomBase( base, tamBase ); // Gera base de busca aleatória e ordenada


        /* CHAVES DE BUSCA:
         * Melhor caso sequencial -> primeiro elemento = base[0].
         * Pior caso sequencial   -> elemento não existe = base[ tamBase-1 ]+1.
         * Melhor caso binária    -> elemento do meio = base[ tamBase/2 ].
         * Pior caso binária      -> elemento não existe = base[ tamBase-1 ]+1.
        */

        /* MEDIÇÃO DO TEMPO DE CADA IMPLEMENTAÇÃO DE BUSCA E COM CHAVES DE BUSCA DIFERENTES */
        tempoExecucaoInsertionSort( arqsaidaInsertionSortMelhor, base, tamBase, base[0] );
        tempoExecucaoInsertionSort( arqsaidaInsertionSortPior, base, tamBase, base[ tamBase-1 ]+1 );
        tempoExecucaoInsertionSort( arqsaidaInsertionSortMedio, base, tamBase, base[ tamBase/2 ] );

        tempoExecucaoSelectionSort( arqsaidaSelectionSortMelhor, base, tamBase, base[0] );
        tempoExecucaoSelectionSort( arqsaidaSelectionSortPior, base, tamBase, base[ tamBase-1 ]+1 );
        tempoExecucaoSelectionSort( arqsaidaSelectionSortMedio, base, tamBase, base[ tamBase/2 ] );

        tempoExecucaoQuickSort( arqsaidaQuickSortMelhor, base, tamBase, base[0] );
        tempoExecucaoQuickSort( arqsaidaQuickSortPior, base, tamBase, base[ tamBase-1 ]+1 );
        tempoExecucaoQuickSort( arqsaidaQuickSortMedio, base, tamBase, base[ tamBase/2 ] );

        tempoExecucaoMergeSort( arqsaidaMergeSortMelhor, base, tamBase, base[0] );
        tempoExecucaoMergeSort( arqsaidaMergeSortPior, base, tamBase, base[ tamBase-1 ]+1 );
        tempoExecucaoMergeSort( arqsaidaMergeSortMedio, base, tamBase, base[ tamBase/2 ] );

    }

    // FECHANDO ARQUIVO COM DADOS BI
    std::cout << "Fechando o arquivo dadosInsertionSort.txt..." << std::endl;
    arqsaidaInsertionSortMelhor.close();
    arqsaidaInsertionSortPior.close();
    arqsaidaInsertionSortMedio.close();

    // FECHANDO ARQUIVO COM DADOS BR
    std::cout << "Fechando o arquivo dadosSelectionSort.txt..." << std::endl;
    arqsaidaSelectionSortMelhor.close();
    arqsaidaSelectionSortPior.close();
    arqsaidaSelectionSortMedio.close();

    // FECHANDO ARQUIVO COM DADOS SI
    std::cout << "Fechando o arquivo dadosQuickSort.txt..." << std::endl;
    arqsaidaQuickSortMelhor.close();
    arqsaidaQuickSortPior.close();
    arqsaidaQuickSortMedio.close();

    // FECHANDO ARQUIVO COM DADOS SR
    std::cout << "Fechando o arquivo dadosMergeSort.txt..." << std::endl;
    arqsaidaMergeSortMelhor.close();
    arqsaidaMergeSortPior.close();
    arqsaidaMergeSortMedioMe.close();


    return 0;

}



/**
 * @brief Realiza a medição do tempo da execução do algoritmo de busca binária recursiva.
 * @details Função implementada fazendo uso das bibliotecas iomanip e time.h.
 * @param arqsaida Arquivo de saída dos dados.
 * @param V Vetor com a base de busca.
 * @param n Tamanho da base de busca.
 * @param x Chave de busca.
 * @return O tempo de execução do algoritmo de busca binária recursiva.
 */
int tempoExecucaoInsertionSort( std::ofstream & arqsaidaInsertionSort, int *V, int n ){


    clock_t Ticks[8];

    Ticks[2] = clock();
    insertionSort( V, n );
    Ticks[3] = clock();
    double tempoInsertionSort = (Ticks[3] - Ticks[2]) * 1000.0 / CLOCKS_PER_SEC;

    // Gravando os registros numéricos
    arqsaidaInsertionSort << n << std::setw(10) << tempoInsertionSort << std::endl;

    // Tratamento de erro de leitura de arquivo
    if( arqsaidaInsertionSort.fail() ) {
        std::cout << "Erro fatal!" << std::endl;
        exit(1); // Aborta programa
    }

    return 0;

}

/**
 * @brief Realiza a medição do tempo da execução do algoritmo de busca sequencial iterartiva.
 * @details Função implementada fazendo uso das bibliotecas iomanip e time.h.
 * @param arqsaida Arquivo de saída dos dados.
 * @param V Vetor com a base de busca.
 * @param n Tamanho da base de busca.
 * @param x Chave de busca.
 * @return O tempo de execução do algoritmo de busca sequencial iterartiva.
 */
int tempoExecucaoSelectionSort( std::ofstream & arqsaidaSelectionSort, int *V, int n ){


    clock_t Ticks[8];

    Ticks[4] = clock();
    selectionSort( V, n);
    Ticks[5] = clock();
    double tempoSelectionSort = (Ticks[5] - Ticks[4]) * 1000.0 / CLOCKS_PER_SEC;

    // Gravando os registros numéricos
    arqsaidaSelectionSort << n << std::setw(10) << tempoSelectionSort << std::endl;

    // Tratamento de erro de leitura de arquivo
    if( arqsaidaSelectionSort.fail() ) {
        std::cout << "Erro fatal!" << std::endl;
        exit(1); // Aborta programa
    }

    return 0;

}

/**
 * @brief Realiza a medição do tempo da execução do algoritmo de busca sequencial recursiva.
 * @details Função implementada fazendo uso das bibliotecas iomanip e time.h.
 * @param arqsaida Arquivo de saída dos dados.
 * @param V Vetor com a base de busca.
 * @param n Tamanho da base de busca.
 * @param x Chave de busca.
 * @return O tempo de execução do algoritmo de busca sequencial recursiva.
 */
int tempoExecucaoQuickSort( std::ofstream & arqsaidaQuickSort, int *V, int inicio, int fim ){

    clock_t Ticks[8];

    Ticks[6] = clock();
    quickSort( V, inicio, fim );
    Ticks[7] = clock();
    double tempoQuickSort = (Ticks[7] - Ticks[6]) * 1000.0 / CLOCKS_PER_SEC;

    // Gravando os registros numéricos
    arqsaidaQuickSort << (inicio - fim) << std::setw(10) << tempoQuickSort << std::endl;

    // Tratamento de erro de leitura de arquivo
    if( arqsaidaQuickSort.fail() ) {
        std::cout << "Erro fatal!" << std::endl;
        exit(1); // Aborta programa
    }

    return 0;

}


/**
 * @brief Realiza a medição do tempo da execução do algoritmo de busca binária iterartiva.
 * @details Função implementada fazendo uso das bibliotecas iomanip e time.h.
 * @param arqsaida Arquivo de saída dos dados.
 * @param V Vetor com a base de busca.
 * @param n Tamanho da base de busca.
 * @param x Chave de busca.
 * @return O tempo de execução do algoritmo de busca binária iterartiva.
 */
int tempoExecucaoMergeSort( std::ofstream & arqsaidaMergeSort, int *V, int inicio, int fim ){


    clock_t Ticks[8];

    Ticks[0] = clock();
    mergesort( V, inicio, fim );
    Ticks[1] = clock();
    double tempoMergeSort = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;

    // Gravando os registros numéricos
    arqsaidaMergeSort << (inicio - fim) << std::setw(10) << tempoMergeSort  << std::endl;

    // Tratamento de erro de leitura de arquivo
    if( arqsaidaMergeSort.fail() ) {
        std::cout << "Erro fatal!" << std::endl;
        exit(1); // Aborta programa
    }

    return 0;

}