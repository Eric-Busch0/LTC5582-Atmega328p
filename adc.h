#ifndef ADC_H
#define ADC_H
#include <stdint.h>
#include <avr/io.h>

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
static inline void adc_disable(void)
{
    ADCSRA &= ~(1 << ADEN);
}
static inline void adc_enable(void)
{
    ADCSRA |= (1 << ADEN);
}
#endif