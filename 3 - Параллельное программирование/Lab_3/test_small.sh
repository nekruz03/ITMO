#!/bin/bash

N1=2300
N2=100000

Delta=$(( (N2-N1)/10 ))

rm -f ./res_small/*


for ((N=N1; N<=N2; N+=Delta)); do

    echo "Running seq for N=$N"
    ./lab3_seq $N >> ./res_small/res_seq.txt

    echo "Running guided for N=$N"
    ./sched/compiled/sched_gu4 $N 4 >> ./res_small/res_gu.txt

    echo "Running static for N=$N"
    ./sched/compiled/sched_stat4 $N 4 >> ./res_small/res_stat.txt

    echo "Running dynamic for N=$N"
    ./sched/compiled/sched_dyn4 $N 4 >> ./res_small/res_dyn.txt
    
done