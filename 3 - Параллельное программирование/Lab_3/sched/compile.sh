#!/bin/bash

gcc -O3 -Wall -Werror dyn/sched_dyn1.c -o compiled/sched_dyn1 -fopenmp -lm
gcc -O3 -Wall -Werror dyn/sched_dyn3.c -o compiled/sched_dyn3 -fopenmp -lm
gcc -O3 -Wall -Werror dyn/sched_dyn4.c -o compiled/sched_dyn4 -fopenmp -lm
gcc -O3 -Wall -Werror dyn/sched_dyn5.c -o compiled/sched_dyn5 -fopenmp -lm


gcc -O3 -Wall -Werror stat/sched_stat1.c -o compiled/sched_stat1 -fopenmp -lm
gcc -O3 -Wall -Werror stat/sched_stat3.c -o compiled/sched_stat3 -fopenmp -lm
gcc -O3 -Wall -Werror stat/sched_stat4.c -o compiled/sched_stat4 -fopenmp -lm
gcc -O3 -Wall -Werror stat/sched_stat5.c -o compiled/sched_stat5 -fopenmp -lm


gcc -O3 -Wall -Werror gu/sched_gu1.c -o compiled/sched_gu1 -fopenmp -lm
gcc -O3 -Wall -Werror gu/sched_gu3.c -o compiled/sched_gu3 -fopenmp -lm
gcc -O3 -Wall -Werror gu/sched_gu4.c -o compiled/sched_gu4 -fopenmp -lm
gcc -O3 -Wall -Werror gu/sched_gu5.c -o compiled/sched_gu5 -fopenmp -lm