# ALGORITMOS DE ORDENACAO


## Sobre o projeto:

Análise empírica dos algoritmos de ordenacao: selectionSort, insertionSort, quickSort e mergeSort. Com medição de tempo e experimentos com vetores de diferentes tamanhos.
        
        
## Como compilar:

Para compilar o projeto, basta digitar, pelo terminal, o comando abaixo

    g++ -std=c++11 src/main.cpp src/ordenacao.cpp src/manager.cpp -I include -o orden
    

Comando para executar o programa
    
    ./orden


## TODO

- [X] Implementar algoritmos de ordenacao.
- [X] Fornecer instancia do problema de ordenacao: vetor de tamanho N.
- [X] Adicionar medição de tempo.
- [X] Salvar dados em arquivo .txt
- [X] Gerar gráfico.

## Gerar gráficos

Os scripts de geração dos gráficos de análise empírica dos algoritmos de busca estão disponíveis neste projeto. Para gerar os gráficos com o gnuplot, basta executar:


gnuplot> load 'grafBI.gnu'
gnuplot> load 'grafBR.gnu'
gnuplot> load 'grafSI.gnu'
gnuplot> load 'grafSR.gnu'



Programa desenvolvido por _Bianca Santiago_ (< *bianca.santiago72@gmail.com* >) e _Jaine Budke_ (< *jainebudke@hotmail.com* >), 2017.1
