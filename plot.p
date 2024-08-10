set datafile separator ','

set key noautotitle

set multiplot layout 2,2

set yrange [-1.5:1.5]
set xrange [0:10]
set xlabel "variable x, degrees"

set ylabel "function y=sine(x)"
plot 'sine.csv' u 1:2 with lines

set ylabel "function y=sine(x)+1"
plot 'sine.csv' u 1:3 with lines

set ylabel "function y=sine(x)*sine(x)"
plot 'sine.csv' u 1:4 with lines

set ylabel "y"
plot 'sine.csv' u 1:4 with lines title "sine(x)*sine(x)", 'sine.csv' u 1:2 with lines title "sine(x)"


pause 0.5
reread