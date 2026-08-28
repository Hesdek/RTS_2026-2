#include <stdio.h>

void check_temperature(float temperature)
{
    const float LIMIT = 80.0;

    /* Dummy workload */
    for (volatile unsigned long i = 0;
         i < 200000UL;
         i++) {
    }

    if (temperature > LIMIT) {
        printf("WARNING: Overtemperature!\n");
    }
}