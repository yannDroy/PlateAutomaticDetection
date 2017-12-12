#!/bin/bash

# Argument test
if [ -z "$1" ]
then
    echo "Argument needed: file"
    exit 1
fi

gnuplot -persist << -EOFMarker
set title "$1"
set xlabel 'Number of threads'
set ylabel 'Time'
plot "$1" using 1:2 with linespoints
-EOFMarker
