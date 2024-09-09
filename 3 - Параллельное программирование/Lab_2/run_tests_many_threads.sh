#!/bin/bash

export LD_LIBRARY_PATH="$PWD/FW_1.3.1_Lin64/lib/"

run_program() {
    echo "Running program with N=$1 and M=$2"
    ./lab2 "$1" "$2" &
    PID=$!
    echo "Program PID: $PID"
    while ps -p $PID > /dev/null; do
        ps -p $PID -o %cpu | tail -n 1 >> tests_results/many_threads/cpu_usage_$2.txt
        sleep 1
    done
    echo "Program with M=$2 completed."
}

N=1150000
M_values=(7 10 16)


for M in "${M_values[@]}"; do
    > tests_results/many_threads/cpu_usage_$M.txt
done

echo "Starting program execution with different values of M..."
for M in "${M_values[@]}"; do
    run_program $N $M
done