#include <inttypes.h>
#include <avr/io.h>

#include "digital.h"
#include "pins.h"

void pin_mode(uint8_t pin, enum mode m) {
    uint8_t bm = pin_to_bit_mask(pin);
    uint8_t port = pin_to_port(pin);

    if (port == NO_PORT) {
        return;
    }

    volatile uint8_t *ddr = port_to_ddr_mapping[port];
    volatile uint8_t *data = port_to_data_mapping[port];

    if (m == OUTPUT) {
        *ddr |= bm;
    } else if (m == INPUT) {
        *ddr &= ~bm;
        *data &= ~bm;
    } else if (m == INPUT_PULLUP) {
        *ddr &= ~bm;
        *data |= bm;
    }
}

void digital_write(uint8_t pin, enum voltage w) {
    uint8_t bm = pin_to_bit_mask(pin);
    uint8_t port = pin_to_port(pin);

    if (port == NO_PORT) {
        return;
    }

    volatile uint8_t *data = port_to_data_mapping[port];
    if (w == HIGH) {
        *data |= bm;
    } else {
        *data &= ~bm;
    }
}

void digital_toggle(uint8_t pin) {
    uint8_t bm = pin_to_bit_mask(pin);
    uint8_t port = pin_to_port(pin);

    if (port == NO_PORT) {
        return;
    }

    volatile uint8_t *data = port_to_data_mapping[port];
    *data ^= bm;
}

enum voltage digital_read(uint8_t pin) {
    uint8_t bm = pin_to_bit_mask(pin);
    uint8_t port = pin_to_port(pin);

    if (port == NO_PORT) {
        return LOW;
    }

    volatile uint8_t *input = port_to_input_mapping[port];
    enum voltage read;
    if (*input & bm) {
        read = HIGH;
    } else {
        read = LOW;
    }

    return read;
}
