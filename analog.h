#ifndef UNOLIB_ANALOG_H
#define UNOLIB_ANALOG_H

/**
 * Writes an analog signal to a pin using pwm.
 * @param pin Pin number
 * @param val Value between 0 and 255
 */
void analog_write(uint8_t pin, uint8_t val);

#endif
