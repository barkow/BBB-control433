//Dummy interface file for compatibility of original RC Swtich implementation with Beaglebone Black
#ifndef _WPROGRAM_H_
#define _WPROGRAM_H_

#include <stdint.h>
#include <unistd.h>
#include "gpio.h"

typedef uint8_t byte;
typedef uint8_t boolean;

#define delayMicroseconds(us) usleep(us)

#endif
