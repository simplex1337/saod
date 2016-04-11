#!/usr/bin/gnuplot
set terminal pngcairo size 800,480 enhanced font 'Arial, 16'
set output 'sort.png'

set style line 1 linecolor rgb 'red' linetype 1 linewidth 2
set style line 2 linecolor rgb 'blue' linetype 1 linewidth 2
set style line 3 linecolor rgb 'green' linetype 1 linewidth 2

set border linewidth 1
set key top left
set grid
set format y "%.6f"
set xlabel "Number of elements" font "Arial, 16"
set format x "%.0f"
set ylabel "Execution time (sec)" font "Arial, 16"
set xtics 100000 font "Arial, 12"
set ytics font "Arial, 12"
set rmargin 4
set tmargin 2
set mxtics

#set output 'sort_all.png'
plot "datamerg.dat" using 1:2 title "Merge Sort" with linespoints ls 1, \
	"databubb.dat" using 1:2 title "Bubble Sort" with linespoints ls 3, \
	"datacoun.dat" using 1:2 title "Counting Sort" with linespoints ls 2

set output 'sort_candm.png'
plot "datamerg.dat" using 1:2 title "Merge Sort" with linespoints ls 1, \
	"datacoun.dat" using 1:2 title "Counting Sort" with linespoints ls 2


