reset session
set datafile separator ","

set key noautotitle

set multiplot layout 1,2
#cool multiplot layout style: https://stackoverflow.com/questions/56477986/double-column-plot-in-gnuplot-multiplot

set xdata time
set timefmt '%Y-%m-%dT%H:%M:%S'
set format x '%Y-%m-%d %H:%M:%S'
set xrange ["2024-08-08":"2024-08-12"] #change this date to your convenience
set xrange [*:*]
#unset xtics
#unset mxtics
set xtics rotate 90

set key outside
set key center top
set key box horizontal
set xtics 120 #SECONDS, change it yo your convenience


set ylabel 'Temperature (C degrees)'
set yrange [0:45]
set y2label 'Humidity (%)'
set y2range [0:120]

set tics nomirror
set y2tics nomirror

set grid

set offsets 120,0,120,0 #margins

plot 'data.csv' using 1:2 axes x1y1 with lines title 'Temperature',\
'data.csv' using 1:3 axes x1y2 with lines title 'Humidity'


set ylabel "Humidy+Temperature (nonsense)"
set yrange [0:150]
unset y2tics
unset y2label
plot 'data.csv' u 1:($2+$3) axes x1y1 with lines title "Humidity+Temperaure"


pause 2 #seconds before plot refresh
reread