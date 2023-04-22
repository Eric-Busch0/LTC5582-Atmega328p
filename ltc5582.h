#ifndef LTC5582_H
#define LTC5582_H


#include <stdint.h>


void ltc5582_init();
void ltc5582_enable();
void ltc5582_disable();
int8_t ltc5582_getPower();


#endif
