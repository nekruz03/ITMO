#!/bin/bash

N1=2300
N2=1150000

Delta=$(( (N2-N1)/10 ))

rm -f ./../tests_results/sched/dyn/*
rm -f ./../tests_results/sched/stat/*
rm -f ./../tests_results/sched/gu/*
rm -f ./../tests_results/sched/res_seq.txt


for ((N=N1; N<=N2; N+=Delta)); do
    echo "Running seq for N=$N"
    ./../lab3_seq $N >> ./../tests_results/sched/res_seq.txt

    echo "Running dyn1 for N=$N"
    ./compiled/sched_dyn1 $N 4 >> ./../tests_results/sched/dyn/res_m1.txt

    echo "Running dyn3 for N=$N"
    ./compiled/sched_dyn3 $N 4 >> ./../tests_results/sched/dyn/res_m3.txt
    
    echo "Running dyn4 for N=$N"
    ./compiled/sched_dyn4 $N 4 >> ./../tests_results/sched/dyn/res_m4.txt

    echo "Running dyn5 for N=$N"
    ./compiled/sched_dyn5 $N 4 >> ./../tests_results/sched/dyn/res_m5.txt




    echo "Running stat1 for N=$N"
    ./compiled/sched_stat1 $N 4 >> ./../tests_results/sched/stat/res_m1.txt

    echo "Running stat3 for N=$N"
    ./compiled/sched_stat3 $N 4 >> ./../tests_results/sched/stat/res_m3.txt

    echo "Running stat4 for N=$N"
    ./compiled/sched_stat4 $N 4 >> ./../tests_results/sched/stat/res_m4.txt

    echo "Running stat5 for N=$N"
    ./compiled/sched_stat5 $N 4 >> ./../tests_results/sched/stat/res_m5.txt




    echo "Running gu1 for N=$N"
    ./compiled/sched_gu1 $N 4 >> ./../tests_results/sched/gu/res_m1.txt

    echo "Running gu3 for N=$N"
    ./compiled/sched_gu3 $N 4 >> ./../tests_results/sched/gu/res_m3.txt

    echo "Running gu4 for N=$N"
    ./compiled/sched_gu4 $N 4 >> ./../tests_results/sched/gu/res_m4.txt

    echo "Running gu5 for N=$N"
    ./compiled/sched_gu5 $N 4 >> ./../tests_results/sched/gu/res_m5.txt
done