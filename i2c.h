#ifndef I2C_H
#define I2C_H

#include <stdint.h>

// I2C initialize
void i2c_init(void);

// I2C start condition
void i2c_start(void);
// I2C stop condition
void i2c_stop(void);
// I2C write function
void i2c_write(uint8_t data);

// I2C read function with acknowledgment
uint8_t i2c_read_ack(void);
// I2C read function without acknowledgment
uint8_t i2c_read_nack(void);
// I2C write byte to slave device
void i2c_write_byte(uint8_t address, uint8_t data);

// I2C read byte from slave device
uint8_t i2c_read_byte(uint8_t address);

#endif