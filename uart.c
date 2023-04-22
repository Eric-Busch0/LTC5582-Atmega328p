#include "uart.h"
#include <avr/io.h>



void uart_init(uint32_t baud)
{
    uint32_t ubrr = F_CPU / (16 * baud) - 1;

    UBRR0H = (uint8_t)(ubrr >> 8);
    UBRR0L = (uint8_t)ubrr;
    /*Enable receiver and transmitter */
    UCSR0B = (1 << RXEN0) | (1 << TXEN0);
}
void uart_putc(uint8_t b)
{
    while (!(UCSR0A & (1 << UDRE0)))
        ;
    /* Put data into buffer, sends the data */
    UDR0 = b;
}
void uart_write(uint8_t *buf, uint32_t len)
{

    for(uint32_t i = 0; i < len; i++)
    {
        uart_putc(buf[i]);
    }
}
void uart_read(uint8_t *buf, uint32_t len)
{
}