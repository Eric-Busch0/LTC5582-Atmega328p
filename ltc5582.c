#include "ltc5582.h"
#include "adc.h"
#include "comparator.h"
#include <avr/io.h>

adc_cfg_t cfg = ADC_DEFAULTS;

#define ENABLE_DIRREG DDRD
#define ENABLE_DIRREG_BIT DDD2
#define ENABLE_PORT PORTD
#define ENABLE_PIN_POS PIND2
#define ENABLE_PIN (1 << ENABLE_PIN_POS)
#define LTC_ADC_CH 0

void ltc5582_init(uint8_t sigDetectEn){
    //configure enable pin
    ENABLE_DIRREG |= (1 << ENABLE_DIRREG_BIT);

    adc_init(&cfg); 
    comparator_init();;

    if(sigDetectEn)
    {
        ltc5582_sigDetectEnable();
    }
    else
    {
        ltc5582_sigDetectDisable();
    }
}


void ltc5582_enable(void)
{
    ENABLE_PORT |= ENABLE_PIN;
}
void ltc5582_disable(void)
{
    ENABLE_PORT &= ~ENABLE_PIN;

}
int8_t ltc5582_getPower(void)
{

    int8_t power = 0;

    ltc5582_enable();
    uint16_t raw = adc_read(LTC_ADC_CH);
    ltc5582_disable();
    // do conversion
    


    return power;
}
void ltc5582_sigDetectEnable(void)
{
    comparator_enable();
}
void ltc5582_sigDetectDisable(void)
{
    comparator_disable();
}