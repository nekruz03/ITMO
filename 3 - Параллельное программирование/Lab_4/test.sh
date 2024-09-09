#!/bin/bash

N1=2300
Nx=20000
N2=1150000

Delta=$(( (N2-(Nx)/2)/10 ))

rm -f ./tests_results/*


for ((N=Nx/2; N<=N2; N+=Delta)); do
    echo "Running M = 1 for N=$N"
    ./lab4 $N 1 >> ./tests_results/res_m1.txt

    echo "Running M = 3 for N=$N"
    ./lab4 $N 3 >> ./tests_results/res_m3.txt

    echo "Running M = 4 for N=$N"
    ./lab4 $N 4 >> ./tests_results/res_m4.txt

    echo "Running M = 5 for N=$N"
    ./lab4 $N 5 >> ./tests_results/res_m5.txt
done