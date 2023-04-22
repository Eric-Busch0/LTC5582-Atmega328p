#ifndef UART_H
#define UART_H

#include <stdint.h>
void uart_init(uint32_t baud);
void uart_putc(uint8_t b);
void uart_write(uint8_t *buf, uint32_t len);
void uart_read(uint8_t *buf, uint32_t len);
#endif