#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <math.h>

void swap(float *a, float *b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}

void combSort(float arr[], int n) {
    int gap = n;
    float shrink = 1.3;
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
struct timeval T1, T2;
long delta_ms;
N = atoi(argv[1]); // N равен первому параметру командной строки
gettimeofday(&T1, NULL); // запомнить текущее время T1


for (i=0; i<5; i++) { // 5 экспериментов
    unsigned int k = i;
    // //Заполнить массив исходных данных размером N

     float* M1 = (float*)malloc(N*sizeof(float));
    for (int j = 0; j < N; j++) {
        M1[j] = rand_r(&k) % 320 + 1; // Случайные числа от 1 до 320
    }

    float* M2 = (float*)malloc((N/2)*sizeof(float));
    for (int j = 0; j < N / 2; j++) {
        M2[j] = (rand_r(&k) % (320 * 9)) + 320; // Случайные числа от 320 до 10*320
    }

    // Решить поставленную задачу, заполнить массив с результатами

    // В массиве М1 к каждому элементу применить операцию гиперболический тангенс с последующим уменьшением на 1
    for(int j = 0; j < N; j++) {
        M1[j] = tanh(M1[j]) - 1;
    }

    // В массиве М2 каждый элемент поочередно сложить с предыдущим (понадобится копия массива М2, из которого нужно будет брать операнды)
    // к результату сложения применить операцию десятичный логарифм, возведенный в степень e (считать, что для начального элемента массива предыдущий элемент равен нулю)
    float* M2_copy = (float*)malloc((N/2)*sizeof(float));
    for(int j = 0; j < N/2; j++){
        M2_copy[j] = M2[j];
        if(j != 0){
            M2[j] = M2_copy[j-1] + M2[j];
        }
        M2[j] = pow(log10(M2[j]), M_E);
    }
    free(M2_copy);

    // В массивах М1 и М2 ко всем элементами с одинаковыми индексами попарно применить операцию деление
    // т.е. M2[i] = M1[i]/M2[i] (результат записать в М2)
    for(int j = 0; j < N/2; j++){
        M2[j] = M1[j]/M2[j];
    }
    
    // Отсортировать массив с результатами указанным методом
    combSort(M2, N/2);

    // Рассчитать сумму синусов тех элементов массива М2, которые при делении на минимальный ненулевой элемент массива М2 дают четное число
    float min = M2[0];
    float x = 0.0f;
    for(int j = 1; j < N/2; j++){
       x += (int)(M2[j]/min) % 2 == 0 ? sin(M2[j]) : 0;
    }

    printf("X: %f\n", x);

}
gettimeofday(&T2, NULL); // запомнить текущее время T2
delta_ms = (T2.tv_sec - T1.tv_sec) * 1000 +
(T2.tv_usec - T1.tv_usec) / 1000;
printf("N=%d. Milliseconds passed=%ld\n", N, delta_ms);
return 0;
}