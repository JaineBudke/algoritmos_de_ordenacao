#Instruções para plotar InsertionSort
reset
set grid
set title "Ordenacao InsertionSort"
set key above
set ylabel "Tempo de Execucao"
set xlabel "Tamanho Base de Busca"
set size 1,1
set term post eps enhanced color
set out 'grafIS.eps'
plot 'dadosInsertionSortMelhor.txt' title 'Melhor caso' with lines, 'dadosInsertionSortMedio.txt' title 'Medio caso' with lines, 'dadosInsertionSorPior.txt' title 'Pior caso' with lines
#Fim