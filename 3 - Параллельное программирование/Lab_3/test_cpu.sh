#/!/bin/bash

run_program() {
    echo "Running program with N=$1 and M=$2"
    ./sched/compiled/sched_gu4 "$1" "$2" &
    PID=$!
    echo "Program PID: $PID"
    while ps -p $PID > /dev/null; do
        ps -p $PID -o %cpu | tail -n 1 >> cpu_usage.txt
        sleep 0.00000000000000000001
    done
    echo "Program with M=$2 completed."
}

N=1150000
M=4

run_program $N $M