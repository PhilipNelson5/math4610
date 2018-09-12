set term png
set output "sinApprox.png"
set title "approximation of d/dx sin(1)"
set xlabel "value of h" offset 0,-5
set ylabel "d/dx sin (1)"
set key outside
set xtics rotate
set xtics axis nomirror in
set ytics axis nomirror in
plot "sin.csv" using 1:2 title "calculated value" with linespoints, \
"sin.csv" using 1:3 title "approximated value" with linespoints

set output "sinError.png"
set title "error of approximation of d/dx sin(1)"
set xlabel "value of h" offset 0,-5
set ylabel "error"
plot "sin.csv" using 1:4 title "absolute error" with linespoints, \
"sin.csv" using 1:5 title "relative error" with linespoints
