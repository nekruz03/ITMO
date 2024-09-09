#!/bin/bash

rm -f ./tests_results/*

N1=2300
N2=1125000

Delta=$(( (N2-N1)/10 ))

for ((N=N1; N<=N2; N+=Delta)); do
    echo "Running seq for N=$N"
    ./compiled/seq $N >> ./tests_results/seq_res.txt
    echo "Running par1 for N=$N"
    ./compiled/par1 $N >> ./tests_results/par1_res.txt
    echo "Running par3 for N=$N"
    ./compiled/par3 $N >> ./tests_results/par3_res.txt
    echo "Running par4 for N=$N"
    ./compiled/par4 $N >> ./tests_results/par4_res.txt
    echo "Running par5 for N=$N"
    ./compiled/par5 $N >> ./tests_results/par5_res.txt
done
