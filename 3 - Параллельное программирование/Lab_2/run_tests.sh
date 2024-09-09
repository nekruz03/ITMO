#!/bin/bash

export LD_LIBRARY_PATH="$PWD/FW_1.3.1_Lin64/lib/"

N1=2300
N2=1150000

Delta=$(( (N2-N1)/10 ))

rm -f ./tests_results/*


for ((N=N1; N<=N2; N+=Delta)); do
    echo "Running M = 1 for N=$N"
    ./lab2 $N 1 >> ./tests_results/res_m1.txt

    echo "Running M = 2 for N=$N"
    ./lab2 $N 2 >> ./tests_results/res_m2.txt

    echo "Running M = 3 for N=$N"
    ./lab2 $N 3 >> ./tests_results/res_m3.txt

    echo "Running M = 4 for N=$N"
    ./lab2 $N 4 >> ./tests_results/res_m4.txt

    echo "Running M = 7 for N=$N"
    ./lab2 $N 7 >> ./tests_results/res_m7.txt

    echo "Running M = 10 for N=$N"
    ./lab2 $N 10 >> ./tests_results/res_m10.txt

    echo "Running M = 16 for N=$N"
    ./lab2 $N 16 >> ./tests_results/res_m16.txt

done