#include <stdint.h>
#include <stdio.h>
#include "gpio.h"

void pinMode(uint8_t bPin, uint8_t bMode)
{
    FILE *pFileDir;
    char abT[100];

    sprintf(abT, "/sys/class/gpio/gpio%d/direction", bPin);
    pFileDir = fopen(abT, "w");

    if(pFileDir == NULL) {
        //GPIO evtl. noch nicht exportiert
        FILE *pFileExport = fopen("/sys/class/gpio/export", "w");
        if(pFileExport == NULL){
            return;
        }
        fseek(pFileExport, 0, SEEK_SET);
        fprintf(pFileExport, "%d", bPin);
        fflush(pFileExport);
        fclose(pFileExport);

        //Erneut versuchen, das direction File zu öffnen
        pFileDir = fopen(abT, "w");
        if(pFileDir == NULL){
            return;
        }
    }
    fseek(pFileDir, 0, SEEK_SET);
    switch(bMode){
        case INPUT:
            fprintf(pFileDir, "in");
            break;
        case OUTPUT:
            fprintf(pFileDir, "out");
            break;
        case INPUT_PULLUP:
            break;
    }
    fflush(pFileDir);
    fclose(pFileDir);
}

static FILE * s_pFileDw = NULL;

void digitalWrite(uint8_t bPin, uint8_t bVal)
{
    char abT[100];
    if (s_pFileDw) {
        fclose(s_pFileDw);
    }
    sprintf(abT, "/sys/class/gpio/gpio%d/value", bPin);
    s_pFileDw = fopen(abT, "w");

    fseek(s_pFileDw, 0, SEEK_SET);
    fprintf(s_pFileDw, "%d\n", (int)bVal);
    fflush(s_pFileDw);
}
