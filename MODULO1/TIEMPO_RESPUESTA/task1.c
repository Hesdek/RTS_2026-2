float acquire_temperature(void)
{
    /*
     * Simulación de adquisición
     */
    float temperature = 72.5;

    /* Dummy workload */
    for (volatile unsigned long i = 0;
         i < 100000UL;
         i++) {
    }

    return temperature;
}