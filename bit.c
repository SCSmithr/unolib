#include "bit.h"

uint8_t bit_read(uint16_t num, uint8_t bit_pos) {
    for (uint8_t i = 0; i < bit_pos; i++) {
        num = num >> 1;
    }

    uint8_t result = num & 1;
    return result;
}
