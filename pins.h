#ifndef UNOLIB_PINS_H
#define UNOLIB_PINS_H

// Aliases for analog pins.
static const uint8_t A0 = 14;
static const uint8_t A1 = 15;
static const uint8_t A2 = 16;
static const uint8_t A3 = 17;
static const uint8_t A4 = 18;
static const uint8_t A5 = 19;

static const uint8_t NO_PIN = 22;
static const uint8_t NO_PORT = 23;

// Indices for accessing the correct registers in the port mapping arrays.
static const uint8_t PD = 0;
static const uint8_t PC = 1;
static const uint8_t PB = 2;

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
uint8_t pin_to_port(uint8_t pin);

#endif
