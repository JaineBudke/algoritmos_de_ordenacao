#Instruções para plotar MergeSort
reset
set grid
set title "Ordenacao MergeSort"
set key above
set ylabel "Tempo de Execucao"
set xlabel "Tamanho Base de Busca"
set size 1,1
set term post eps enhanced color
set out 'grafMS.eps'
plot 'dadosMergeSortMelhor.txt' title 'Melhor caso' with lines, 'dadosMergeSortMedio.txt' title 'Medio caso' with lines, 'dadosMergeSortPior.txt' title 'Pior caso' with lines
#Fim
