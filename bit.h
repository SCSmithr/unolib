#ifndef UNOLIB_BIT_H
#define UNOLIB_BIT_H

#include <inttypes.h>

/**
 * Read a bit at a given position
 * @param  num     Number to read bit from
 * @param  bit_pos Position of bit (0 being right most bit)
 * @return         0 or 1
 */
uint8_t bit_read(uint16_t num, uint8_t bit_pos);

#endif
