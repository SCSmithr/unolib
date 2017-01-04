#ifndef UNOLIB_DELAY_H
#define UNOLIB_DELAY_H

#include <inttypes.h>

/*
 * The delay functions found in util/delay.h expect constants at compile time.
 * The following functions are wrappers that allow a variable number of ms/ us.
 */

/**
 * Delay a given number of milliseconds.
 * @param ms
 */
void delay_ms(uint16_t ms);

/**
 * Delay a given number of microseconds.
 * @param us
 */
void delay_us(uint16_t us);

#endif
