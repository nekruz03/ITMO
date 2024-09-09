#include <omp.h>
#include <stdio.h>

int main() {
    omp_sched_t kind;
    int chunk_size;

    // Получить текущий тип расписания и размер чанка
    omp_get_schedule(&kind, &chunk_size);

    // Вывести текущий тип расписания и размер чанка
    switch(kind) {
        case omp_sched_static:
            printf("Текущее расписание: Static\n");
            break;
        case omp_sched_dynamic:
            printf("Текущее расписание: Dynamic\n");
            break;
        case omp_sched_guided:
            printf("Текущее расписание: Guided\n");
            break;
        case omp_sched_auto:
            printf("Текущее расписание: Auto\n");
            break;
        default:
            printf("Текущее расписание: Неизвестно\n");
    }

    printf("Размер чанка: %d\n", chunk_size);

    return 0;
}