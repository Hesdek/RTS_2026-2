#include <stdio.h>

#include "task1.h"
#include "task2.h"
#include "task3.h"

int main(void)
{
    float temperature;
    float filtered_temperature;

    printf("========================================\n");
    printf(" Motor Temperature Monitoring System\n");
    printf("========================================\n\n");

    /* Task 1: Sensor acquisition */
    temperature = acquire_temperature();

    printf("Measured temperature: %.2f C\n", temperature);

    /* Task 2: Temperature processing */
    filtered_temperature =
        filter_temperature(temperature);

    printf("Filtered temperature: %.2f C\n",
           filtered_temperature);

    /* Task 3: Temperature supervision */
    check_temperature(filtered_temperature);

    printf("\nApplication finished.\n");

    return 0;
}