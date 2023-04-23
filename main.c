#include <string.h>
#include <stdio.h>
#include <util/delay.h>
#include "comparator.h"
#include "adc.h"
#include "uart.h"
#include "ltc5582.h"

void setup()
{
    ltc5582_init(LTC_SIG_DETECT_EN);
    uart_init(115200);
}
int main()
{
    
    char msg[32] = {0};
    int8_t power = 0;
    while (1)
    {
        power = ltc5582_getPower();

        snprintf(msg, sizeof(msg), "Read:%u\r\n", power);
        uart_write(msg, strlen(msg));
        _delay_ms(1000);

    }
    
}