#Instruções para plotar QuickSort
reset
set grid
set title "Ordenacao QuickSort"
set key above
set ylabel "Tempo de Execucao"
set xlabel "Tamanho Base de Busca"
set size 1,1
set term post eps enhanced color
set out 'grafQS.eps'
plot 'dadosQuickSortMelhor.txt' title 'Melhor caso' with lines, 'dadosQuickSortMedio.txt' title 'Medio caso' with lines, 'dadosQuickSortPior.txt' title 'Pior caso' with lines
#Fim
