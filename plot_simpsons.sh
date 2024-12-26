#!/usr/bin/env bash

# Example data is sent to /tmp/output.
cat > /tmp/output <<herestr
2,3.139999999999999680256
4,3.139999999999999680256
6,3.139999999999999680256
8,3.139999999999999680256
10,3.140000000000000124345
12,3.139999999999999680256
14,3.140000000000000124345
16,3.139999999999999680256
18,3.140000000000000124345
20,3.140000000000000124345
herestr

# Plot the data, specifying that commas are used as the delimiter.
gnuplot <<EOF
    set terminal pdf
    set output "func_integral_graph.pdf"
    set datafile separator ","
    set xlabel "Number of Partitions"
    set ylabel "Integral between 0 and pi"
    set title "Integral of sqrt(sin^2(x)+cos^2(x)) Using Simpson's 1/3 Rule"
    plot "/tmp/output" with linespoints notitle
EOF
