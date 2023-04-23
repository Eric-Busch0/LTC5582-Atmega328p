#include "i2c.h"
#include <avr/io.h>
#include <util/twi.h>
#include <util/delay.h>

#define SCL_CLOCK 100000UL // I2C clock speed in Hz

// I2C initialize
void i2c_init(void)
{
    // set bit rate register
    TWBR = ((F_CPU/SCL_CLOCK)-16)/2;
}

// I2C start condition
void i2c_start(void)
{
    // send start condition
    TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
    // wait for start condition to be transmitted
    while(!(TWCR & (1<<TWINT)));
}

// I2C stop condition
void i2c_stop(void)
{
    // send stop condition
    TWCR = (1<<TWINT)|(1<<TWSTO)|(1<<TWEN);
    // wait for stop condition to be transmitted
    while(TWCR & (1<<TWSTO));
}

// I2C write function
void i2c_write(uint8_t data)
{
    // load data into data register
    TWDR = data;
    // start transmission of data
    TWCR = (1<<TWINT)|(1<<TWEN);
    // wait for data transmission to complete
    while(!(TWCR & (1<<TWINT)));
}

// I2C read function with acknowledgment
uint8_t i2c_read_ack(void)
{
    // start reception of data with acknowledgment
    TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
    // wait for data reception to complete
    while(!(TWCR & (1<<TWINT)));
    // return received data from data register
    return TWDR;
}

// I2C read function without acknowledgment
uint8_t i2c_read_nack(void)
{
    // start reception of data without acknowledgment
    TWCR = (1<<TWINT)|(1<<TWEN);
    // wait for data reception to complete
    while(!(TWCR & (1<<TWINT)));
    // return received data from data register
    return TWDR;
}

// I2C write byte to slave device
void i2c_write_byte(uint8_t address, uint8_t data)
{
    // send start condition
    i2c_start();
    // send slave address with write operation
    i2c_write(address << 1);
    // send data to slave
    i2c_write(data);
    // send stop condition
    i2c_stop();
}

// I2C read byte from slave device
uint8_t i2c_read_byte(uint8_t address)
{
    uint8_t data;
    // send start condition
    i2c_start();
    // send slave address with read operation
    i2c_write((address << 1) | 1);
    // read data from slave with nack
    data = i2c_read_nack();
    // send stop condition
    i2c_stop();
    // return received data
    return data;
}