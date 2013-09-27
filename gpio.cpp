#include <stdint.h>
#include <stdio.h>

void pinMode(uint8_t bPin, uint8_t bMode)
{
}

static FILE * s_pFileDw = NULL;

void digitalWrite(uint8_t bPin, uint8_t bVal)
{
    if (s_pFileDw) {
        fclose(s_pFileDw);
    }
    s_pFileDw = fopen("/sys/class/gpio/gpio60/value", "w");
    fseek(s_pFileDw, 0, SEEK_SET);
    fprintf(s_pFileDw, "%d\n", (int)bVal);
    fflush(s_pFileDw);
}
