#ifndef UNOLIB_ANALOG_H
#define UNOLIB_ANALOG_H

#include <inttypes.h>

/**
 * Writes an analog signal to a pin using pwm.
 * @param pin Pin number
 * @param val Value between 0 and 255
 */
void analog_write(uint8_t pin, uint8_t val);

/**
 * Reads an input from an analog pin.
 * @param  pin Analog pin (A0 to A5)
 * @return     Value between 0 and 1023
 */
uint16_t analog_read(uint8_t pin);

#endif
