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

plot "merge.log" using 1:2 title "MergeSort" with linespoints ls 2
plot "odd.log" using 2:2 title "OddSort" with linespoints ls 2
plot "radix.log" using 3:2 title "RadixSort" with linespoints ls 2

