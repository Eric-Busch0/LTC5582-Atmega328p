#include "comparator.h"
#include <avr/io.h>
#include <avr/interrupt.h>

#define RF_CAPTURE_DIRREG DDRD
#define RF_CAPTURE_DIR_BIT DD4
#define RF_CAPTURE_PORT PORTD
#define RF_CAPTURE_PIN_POS PORTD4
#define RF_CAPTURE_PIN (1 << RF_CAPTURE_PIN_POS)


ISR(ANALOG_COMP_vect)
{
    
    if(ACSR & (1 << ACO))
    {
        RF_CAPTURE_PORT |= RF_CAPTURE_PIN;
    }
    else
    {
        RF_CAPTURE_PORT &= ~RF_CAPTURE_PIN;
    }
}

void comparator_init(void)
{
    cli();
    
    comparator_enable();
    ACSR |= (1 << ACIE);

    RF_CAPTURE_DIRREG |= (1 << RF_CAPTURE_DIR_BIT);
    RF_CAPTURE_PORT &= ~RF_CAPTURE_PIN;
    sei();
}
void comparator_enable(void)
{
    ACSR &= ~(1 << ACD);
}
void comparator_disable(void)
{
    ACSR |= (1 << ACD);
    
}

uint8_t comparator_get_status(void)
{
    return ACSR & (1 << ACO) ? 1 : 0;
}
