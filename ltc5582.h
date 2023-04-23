#ifndef LTC5582_H
#define LTC5582_H


#include <stdint.h>

#define LTC_SIG_DETECT_EN 1
#define LTC_SIG_DETECT_DIS 0

void ltc5582_init(uint8_t sigDetectEnable);
void ltc5582_enable(void);
void ltc5582_disable(void);
int8_t ltc5582_getPower(void);
void ltc5582_sigDetectEnable(void);
void ltc5582_sigDetectDisable(void);

#endif
