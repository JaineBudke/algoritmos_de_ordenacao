/**
 * @file        manager.cpp
 * @brief   Código fonte com a implementacao de funcoes que
                 realizam o gerenciamento do processo da análise empírica.
 * @author  Bianca Santiago (bianca.santiago72@gmail.com)
 * @author  Jaine Budke (jainebudke@hotmail.com)
 * @since   18/04/2017
 * @date    22/05/2017
 */

#include "ordenacao.h"
#include "manager.h"

#include <chrono>
#include <ctime>


/**
 * @brief Gera a base de busca aleatória.
 * @details Função implementada fazendo uso das bibliotecas ctime e cstdlib.
 * @param base Vetor com a base de busca.
 * @param tamBase Tamanho da base de busca.
 */
void generateRandomBase( int *base, int tamBase ){

    for ( int i = 0; i < tamBase; ++i ) { // gerando base de busca
        int num_aleatorio = std::rand() % 200000; // número aleatório entre 0 e 2000
        base[i] = num_aleatorio; // Add valor à base
    }

}


/**
 * @brief Analisa a base de dados gerada apontando o melhor, pior e médio caso dos algoritmos de ordenação.
 * @param tamBase Tamanho da base de busca.
 */
void analiseCasosIS( int tamBase ){

    int base[ tamBase ];   // Vetor com base de busca

    // ==================================
    // gera base de dados e tempo para inicializar melhor e pior tempo
    // ==================================
    generateRandomBase( base, tamBase );
    double tempo = tempoExecucaoIS( base, tamBase );

    // declara e inicializa variaveis de medicao de tempo
    int melhorTempo = tempo;
    int piorTempo = tempo;
    int medioTempo;
    int somaTempos = 0;


    // roda 100x cada base
    for ( int i = 0; i < 100; ++i ) {

        // gera base de dados
        generateRandomBase( base, tamBase );

        // recebendo tempo que levou para ordenar base
        double tempo = tempoExecucaoIS( base, tamBase );
        //std::cout << "Tempo: " << tempo << "milliseconds\n";

        // atualizando pior e melhor caso
        if ( tempo < melhorTempo ) { // verifica se o novo tempo é menor que o melhor computado
            melhorTempo = tempo; // novo tempo é dado como o melhor marcado
        } else if ( tempo > piorTempo ) { // verifica se o novo tempo é maior que o pior computado
            piorTempo = tempo; // novo tempo é dado como o pior marcado
        }

        // atualizando somatorio dos tempos
        somaTempos += tempo;

    }

    // denotando o tempo médio de ordenação
    medioTempo = ( somaTempos - piorTempo - melhorTempo )/98;

    std::cout << "Pior caso: " << piorTempo << "\nMelhor caso: " << melhorTempo << "\nMédio caso: " << medioTempo << "\n";

}


/**
 * @brief Realiza a medição do tempo da execução da ordenacao de uma base de dados com o insertionSort.
 * @details Função implementada fazendo uso das bibliotecas iomanip e time.h.
 * @param V Vetor com a base de dados.
 * @param n Tamanho da base de dados.
 * @return O tempo de execução da ordenacao.
 */
int tempoExecucaoIS( int *V, int n ){


    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();
    insertionSort( V, n ); // ordena vetor com insertionSort
    //quickSort( V, 0, n-1 );
    //selectionSort( V, n );
    end = std::chrono::system_clock::now();

    int elapsed_seconds = std::chrono::duration_cast<std::chrono::milliseconds> (end-start).count();

    return elapsed_seconds;


}

/**
 * @brief Analisa a base de dados gerada apontando o melhor, pior e médio caso dos algoritmos de ordenação.
 * @param tamBase Tamanho da base de busca.
 */
void analiseCasosSS( int tamBase ){

    int base[ tamBase ];   // Vetor com base de busca

    // ==================================
    // gera base de dados e tempo para inicializar melhor e pior tempo
    // ==================================
    generateRandomBase( base, tamBase );
    double tempo = tempoExecucaoSS( base, tamBase );

    // declara e inicializa variaveis de medicao de tempo
    int melhorTempo = tempo;
    int piorTempo = tempo;
    int medioTempo;
    int somaTempos = 0;


    // roda 100x cada base
    for ( int i = 0; i < 100; ++i ) {

        // gera base de dados
        generateRandomBase( base, tamBase );

        // recebendo tempo que levou para ordenar base
        double tempo = tempoExecucaoSS( base, tamBase );
        //std::cout << "Tempo: " << tempo << "milliseconds\n";

        // atualizando pior e melhor caso
        if ( tempo < melhorTempo ) { // verifica se o novo tempo é menor que o melhor computado
            melhorTempo = tempo; // novo tempo é dado como o melhor marcado
        } else if ( tempo > piorTempo ) { // verifica se o novo tempo é maior que o pior computado
            piorTempo = tempo; // novo tempo é dado como o pior marcado
        }

        // atualizando somatorio dos tempos
        somaTempos += tempo;

    }

    // denotando o tempo médio de ordenação
    medioTempo = ( somaTempos - piorTempo - melhorTempo )/98;

    std::cout << "Pior caso: " << piorTempo << "\nMelhor caso: " << melhorTempo << "\nMédio caso: " << medioTempo << "\n";

}


/**
 * @brief Realiza a medição do tempo da execução da ordenacao de uma base de dados com o insertionSort.
 * @details Função implementada fazendo uso das bibliotecas iomanip e time.h.
 * @param V Vetor com a base de dados.
 * @param n Tamanho da base de dados.
 * @return O tempo de execução da ordenacao.
 */
int tempoExecucaoSS( int *V, int n ){


    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();
    //insertionSort( V, n ); // ordena vetor com insertionSort
    //quickSort( V, 0, n-1 );
    selectionSort( V, n );
    end = std::chrono::system_clock::now();

    int elapsed_seconds = std::chrono::duration_cast<std::chrono::milliseconds> (end-start).count();

    return elapsed_seconds;


}
