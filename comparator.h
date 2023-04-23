#ifndef COMPARATOR_H
#define COMPARATOR_H

#include <stdint.h>

void comparator_init(void);
void comparator_enable(void);
void comparator_disable(void);
uint8_t comparator_get_status(void);

#endif