#include <stdio.h>

#include "task1.h"

#define ITERATIONS 1000UL

int main(void)
{
    float temperature = 72.5f;

    printf("========================================\n");
    printf(" Task 1 - Temperature Acquisition\n");
    printf("========================================\n");

    printf("Iterations: %lu\n", ITERATIONS);

    for (unsigned long i = 0; i < ITERATIONS; i++) {
        temperature = acquire_temperature();
    }

    printf("Final temperature: %.2f C\n", temperature);

    return 0;
}