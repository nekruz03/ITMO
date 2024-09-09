#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

#ifdef _OPENMP
    #include <omp.h>
#else
    int omp_get_num_threads() { return 1; }
    double omp_get_wtime() {
        struct timeval tv;
        gettimeofday(&tv, NULL);
        return (double)tv.tv_sec + (double)tv.tv_usec / 1000000.0;
    }
    void omp_set_num_threads(int num_threads) { (void)num_threads; }
    int omp_get_num_procs() { return 1; }
#endif

volatile int progress = 0; // Global variable to track progress

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

        for (int i = 0; i < n - gap; i++) {
            if (arr[i] > arr[i + gap]) {
                swap(&arr[i], &arr[i + gap]);
                swapped = 1;
            }
        }
    }
}

void merge(float arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    float *L = (float *)malloc(n1 * sizeof(float));
    float *R = (float *)malloc(n2 * sizeof(float));

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) {
        arr[k++] = L[i++];
    }

    while (j < n2) {
        arr[k++] = R[j++];
    }

    free(L);
    free(R);
}

void parallelSort(float arr[], int n) {
    int num_procs = omp_get_num_procs();
    int chunk_size = n / num_procs;

    #pragma omp parallel
    {
        int tid = omp_get_thread_num();
        int start = tid * chunk_size;
        int end = (tid == num_procs - 1) ? n : start + chunk_size;
        combSort(arr + start, end - start);
    }

    for (int i = 1; i < num_procs; i++) {
        merge(arr, 0, i * chunk_size - 1, (i + 1) * chunk_size - 1);
    }
}


unsigned int custom_seed(int iteration, int element) {
    return (unsigned int)(iteration * 12345 + element * 67890);
}

void report_progress(int total_experiments) {
    while (progress < total_experiments) {
        printf("Progress: %d%%\n", (progress * 100) / total_experiments);
        sleep(1);
    }
    printf("Progress: 100%%\n");
}

int main(int argc, char* argv[]) {
    int i, N;
    unsigned int M;
    double start_time, end_time;
    long delta_ms;
    int total_experiments = 100;

    if (argc != 3) {
        printf("Usage: %s <N> <M>\n", argv[0]);
        return -1;
    }

    N = atoi(argv[1]); // N равен первому параметру командной строки
    M = atoi(argv[2]);
    omp_set_num_threads(M);

    start_time = omp_get_wtime(); // запомнить текущее время T1

    #pragma omp parallel
    {
        #pragma omp single
        {
            #pragma omp task
            {
                report_progress(total_experiments);
            }
            
            for (i = 0; i < total_experiments; i++) { // 100 экспериментов
                // Заполнить массив исходных данных размером N
                float* M1 = (float*)malloc(N * sizeof(float));
                #pragma omp parallel for default(none) shared(M1, N, i) schedule(guided, 4)
                for (int j = 0; j < N; j++) {
                    unsigned int seed = custom_seed(i, j);
                    M1[j] = rand_r(&seed) % 320 + 1; // Случайные числа от 1 до 320
                } 

                float* M2 = (float*)malloc((N/2)*sizeof(float));
                #pragma omp parallel for default(none) shared(M2, N, i) schedule(guided, 4)
                for (int j = 0; j < N / 2; j++) {
                    unsigned int seed = custom_seed(i, j);
                    M2[j] = (rand_r(&seed) % (320 * 9)) + 320; // Случайные числа от 320 до 10*320
                }

                // Решить поставленную задачу, заполнить массив с результатами

                // В массиве М1 к каждому элементу применить операцию гиперболический тангенс с последующим уменьшением на 1
                #pragma omp parallel for default(none) shared(M1, N) schedule(guided, 4)
                for (int j = 0; j < N; j++) {
                    M1[j] = tanh(M1[j]) - 1;
                }

                // В массиве М2 каждый элемент поочередно сложить с предыдущим (понадобится копия массива М2, из которого нужно будет брать операнды)
                // к результату сложения применить операцию десятичный логарифм, возведенный в степень e (считать, что для начального элемента массива предыдущий элемент равен нулю)
                float* M2_copy = (float*)malloc((N / 2) * sizeof(float));

                #pragma omp parallel for default(none) shared(M2, M2_copy, N) schedule(guided, 4)
                for(int j = 0; j < N/2; j++){
                    M2_copy[j] = M2[j];
                }

                #pragma omp parallel for default(none) shared(M2, M2_copy, N) schedule(guided, 4)
                for (int j = 0; j < N / 2; j++) {
                        if (j != 0) {
                            M2[j] = M2_copy[j - 1] + M2[j];
                        }
                        M2[j] = pow(log10(M2[j]), M_E);
                }
                free(M2_copy);

                #pragma omp parallel for default(none) shared(M2, M1, N) schedule(guided, 4)
                for(int j = 0; j < N/2; j++){
                    M2[j] = M1[j]/M2[j];
                } 

                // Отсортировать массив с результатами указанным методом
                parallelSort(M2, N / 2);


                // Рассчитать сумму синусов тех элементов массива М2, которые при делении на минимальный ненулевой элемент массива М2 дают четное число
                float min = M2[0];
                float x = 0.0f;
                #pragma omp parallel for default(none) shared(M2, min, N) reduction(+:x) schedule(guided, 4)
                for (int j = 1; j < N / 2; j++) {
                    if ((int)(M2[j] / min) % 2 == 0) {
                        x += sin(M2[j]);
                    }
                }

                printf("X: %f\n", x);

                free(M1);
                free(M2);

                #pragma omp atomic
                progress++;
            }
        }
    }

    end_time = omp_get_wtime(); // запомнить текущее время T2
    delta_ms = (long)((end_time - start_time) * 1000);
    printf("N=%d. Milliseconds passed=%ld\n", N, delta_ms);

    return 0;
}
