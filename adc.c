#include "adc.h"
#include <avr/io.h>
#include <string.h>

static adc_cfg_t adcCfg;
void adc_init(adc_cfg_t *cfg)
{
    memcpy(&adcCfg, cfg, sizeof(adc_cfg_t));

}

uint16_t adc_read(uint8_t channel)
{
    ADCSRA |= (1 << ADEN);

    // Select channel 
    ADMUX |= channel & 8;
    
    //Clear interrupt flag
    ADCSRA |= (1 << ADIF);

    // Start conversion
    ADCSRA |= (1 << ADSC);

    //Wait for conversion
    while(!(ADCSRA & (1 << ADIF)));

    const uint16_t result = (ADCH << 8) | ADCL; 

    ADCSRA &= ~(1 << ADEN);

    // return result
    return result;
}