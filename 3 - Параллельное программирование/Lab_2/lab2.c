#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <math.h>

#include "FW_1.3.1_Lin64/fwBase.h"
#include "FW_1.3.1_Lin64/fwSignal.h"

void swap(Fw64f *a, Fw64f *b) {
    Fw64f temp = *a;
    *a = *b;
    *b = temp;
}

void combSort(Fw64f arr[], int n) {
    int gap = n;
    Fw64f shrink = 1.3;
    int swapped = 1;

    while (gap > 1 || swapped) {
        if (gap > 1)
            gap = (int)(gap / shrink);

        swapped = 0;

        for (int i = 0; i + gap < n; i++) {
            if (arr[i] > arr[i + gap]) {
                swap(&arr[i], &arr[i + gap]);
                swapped = 1;
            }
        }
    }
}


int main(int argc, char* argv[]) {
int i, N;
unsigned int M;
struct timeval T1, T2;
long delta_ms;
N = atoi(argv[1]); // N равен первому параметру командной строки
M = atoi(argv[2]);
fwSetNumThreads(M);
gettimeofday(&T1, NULL); // запомнить текущее время T1


for (i=0; i<100; i++) { // 100 экспериментов
    unsigned int k = i;
    // //Заполнить массив исходных данных размером N

     Fw64f* M1 = fwsMalloc_64f(N);
    for (int j = 0; j < N; j++) {
        M1[j] = rand_r(&k) % 320 + 1; // Случайные числа от 1 до 320
    }

    Fw64f* M2 = fwsMalloc_64f(N/2);
    for (int j = 0; j < N / 2; j++) {
        M2[j] = (rand_r(&k) % (320 * 9)) + 320; // Случайные числа от 320 до 10*320
    }


    fwsTanh_64f_A50(M1,M1, N);
    Fw64f* M2_copy = fwsMalloc_64f(N/2);
    fwsAdd_64f(M2+1, M2_copy, M2+1, N/2 - 1);

    free(M2_copy); // Освобождаем память

    fwsDiv_64f(M1, M2, M2, N/2);

    // Отсортировать массив с результатами указанным методом
    combSort(M2, N/2);

    // Рассчитать сумму синусов тех элементов массива М2, которые при делении на минимальный ненулевой элемент массива М2 дают четное число
    Fw64f min = M2[0];
    Fw64f x = 0.0f;
    fwsDivC_64f(M2,min, M2, N / 2);
for(int j = 0; j < N/2; j++){
    if ((int)(M2[j]) % 2 != 0) {
        M2[j] = 0;
    }
}
fwsSin_64f_A50(M2, M2, N/2);
 	fwsSum_64f(M2, N/2, &x);



    printf("X: %f\n", x);

}
gettimeofday(&T2, NULL); // запомнить текущее время T2
delta_ms = (T2.tv_sec - T1.tv_sec) * 1000 +
(T2.tv_usec - T1.tv_usec) / 1000;
printf("N=%d. Milliseconds passed=%ld\n", N, delta_ms);
return 0;
}