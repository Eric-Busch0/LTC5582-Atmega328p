CC=avr-gcc
TARGET_NAME=main
SRC=${TARGET_NAME}.c
SRC+=adc.c \
	comparator.c\
	ltc5582.c\
	uart.c
CDEFS+=-DF_CPU=16000000

HEX = ${TARGET_NAME}.hex
OUT=${BUILD_DIR}${TARGET_NAME}.elf
INSTRUCTION_SET=atmega328p
OPTIMIZATIONS=-O2
BUILD_DIR=build/
#avrdude stuff
AVRDUDECONF=/etc/avrdude.conf
TARGET_MCU=atmega328p
PROGRAMMER=usbtiny

default: compile tohex

tohex: 
	avr-objcopy -O ihex -j.text -j.data ${OUT} ${BUILD_DIR}${HEX}

compile: 
	${CC} ${OPTIMIZATIONS}  -mmcu=${INSTRUCTION_SET} ${SRC} ${CDEFS}  -o ${OUT}
	avr-objdump -S ${OUT} > ${OUT}.lss

flash: 
	avrdude -C ${AVRDUDECONF} -p ${TARGET_MCU} -c ${PROGRAMMER} -U flash:w:${OUT}

.PHONY: clean
clean:
	rm build/*