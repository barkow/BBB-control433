#ifndef _GPIO_H_
#define _GPIO_H_

#include <stdint.h>

#define INPUT 0x0
#define OUTPUT 0x1
#define INPUT_PULLUP 0x2

#define HIGH 1
#define LOW 0

void pinMode(uint8_t bPin, uint8_t bMode);
void digitalWrite(uint8_t bPin, uint8_t bVal);

//Dummy Definitions of not implemented functions
#define attachInterrupt(arg1, arg2, arg3)
#define detachInterrupt(arg1)
#define micros(ms) 0

#endif
