#include <stdio.h>

#include "task3.h"

#define ITERATIONS 1000UL

int main(void)
{
    const float temperature = 72.5f;

    printf("========================================\n");
    printf(" Task 3 - Temperature Supervision\n");
    printf("========================================\n");

    printf("Iterations: %lu\n", ITERATIONS);
    printf("Temperature: %.2f C\n", temperature);

    for (unsigned long i = 0; i < ITERATIONS; i++) {
        check_temperature(temperature);
    }

    printf("Task 3 completed.\n");

    return 0;
}