float filter_temperature(float temperature)
{
    float filtered = temperature;

    /* Dummy processing */
    for (volatile unsigned long i = 0;
         i < 200000UL;
         i++) {
    }

    return filtered;
}