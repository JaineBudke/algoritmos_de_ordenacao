#Instruções para plotar SelectionSort
reset
set grid
set title "Ordenacao SelectionSort"
set key above
set ylabel "Tempo de Execucao"
set xlabel "Tamanho Base de Busca"
set size 1,1
set term post eps enhanced color
set out 'grafSS.eps'
plot 'dadosSelectionSortMelhor.txt' title 'Melhor caso' with lines, 'dadosSelectionSortMedio.txt' title 'Medio caso' with lines, 'dadosSelectionSortPior.txt' title 'Pior caso' with lines
#Fim
