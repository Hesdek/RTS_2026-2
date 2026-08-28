#include <stdio.h>

#include "task2.h"

#define ITERATIONS 1000UL

int main(void)
{
    const float temperature = 72.5f;
    float filtered_temperature = 0.0f;

    printf("========================================\n");
    printf(" Task 2 - Temperature Filtering\n");
    printf("========================================\n");

    printf("Iterations: %lu\n", ITERATIONS);
    printf("Input temperature: %.2f C\n", temperature);

    for (unsigned long i = 0; i < ITERATIONS; i++) {
        filtered_temperature =
            filter_temperature(temperature);
    }

    printf("Final filtered temperature: %.2f C\n",
           filtered_temperature);

    return 0;
}