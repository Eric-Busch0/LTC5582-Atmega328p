#ifndef ADC_H
#define ADC_H
#include <stdint.h>

typedef struct{
    uint8_t vref;
    uint8_t prescaler;
}adc_cfg_t;

#define ADC_DEFAULTS \
{\
    .vref = 0,\
    .prescaler = 0x4\
}

void adc_init(adc_cfg_t *cfg);
uint16_t adc_read(uint8_t channel);

#endif