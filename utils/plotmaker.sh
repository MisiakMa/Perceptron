#!/bin/bash

cat << EOF | gnuplot
set term 'pdf' font 'Liberation Sans'
set wyjscie '$2'
set xlabel "Epoka"
set yrange [0:]
plot '$1' using 1:2 ti "Maksymalny błąd sieci" pt 7 ps 0.2
quit
EOF
