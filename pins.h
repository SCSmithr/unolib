#ifndef UNOLIB_PINS_H
#define UNOLIB_PINS_H

// Aliases for analog pins.
enum analog_alias {
    A0 = 14,
    A1 = 15,
    A2 = 16,
    A3 = 17,
    A4 = 18,
    A5 = 19,
};

static const uint8_t NO_PIN = 22;

// Indices for accessing the correct registers in the port mapping arrays.
enum port_index {
    PD = 0,
    PC = 1,
    PB = 2,

    NO_PORT = 11,
};

enum timer_id {
    T0A,
    T0B,
    T1A,
    T1B,
    T2A,
    T2B,

    NOT_A_TIMER,
};

extern volatile uint8_t* port_to_ddr_mapping[];

extern volatile uint8_t* port_to_data_mapping[];

extern volatile uint8_t* port_to_input_mapping[];

/**
 * Get the byte value of a given pin according to which port the pin is
 * connected to.
 * @param  pin Pin number as labelled on Arduino board
 * @return     Byte value of pin
 */
uint8_t pin_to_bit_mask(uint8_t pin);

/**
 * Determined which port a given pin is connected to. The returned value is
 * an index for use with the port mapping arrays (eg. port_to_data_mapping).
 * @param  pin Pin number as labelled on Arduino board
 * @return     Port index constant
 */
enum port_index pin_to_port(uint8_t pin);

/**
 * Used to identify which timer control register to use for writing an analog
 * signal.
 * @param  pin Pin number as labelled on Arduino board
 * @return     Timer ideitifier
 */
enum timer_id pin_to_timer(uint8_t pin);

#endif
