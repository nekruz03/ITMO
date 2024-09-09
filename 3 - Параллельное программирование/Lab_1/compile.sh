#!/bin/bash

gcc -O3 -Wall -Werror -o gcc/compiled/seq lab1.c -lm
gcc -O3 -Wall -Werror -floop-parallelize-all -ftree-parallelize-loops=1 lab1.c -o gcc/compiled/par1 -lm
gcc -O3 -Wall -Werror -floop-parallelize-all -ftree-parallelize-loops=3 lab1.c -o gcc/compiled/par3 -lm
gcc -O3 -Wall -Werror -floop-parallelize-all -ftree-parallelize-loops=4 lab1.c -o gcc/compiled/par4 -lm
gcc -O3 -Wall -Werror -floop-parallelize-all -ftree-parallelize-loops=5 lab1.c -o gcc/compiled/par5 -lm


clang -O3 -Wall -Werror lab1.c -o clang/compiled/seq -lm
clang -O3 -Wall -Werror -fopenmp -DOMP_NUM_THREADS=1 lab1.c -o clang/compiled/par1 -lm
clang -O3 -Wall -Werror -fopenmp -DOMP_NUM_THREADS=3 lab1.c -o clang/compiled/par3 -lm
clang -O3 -Wall -Werror -fopenmp -DOMP_NUM_THREADS=4 lab1.c -o clang/compiled/par4 -lm
clang -O3 -Wall -Werror -fopenmp -DOMP_NUM_THREADS=5 lab1.c -o clang/compiled/par5 -lm