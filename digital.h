#ifndef UNOLIB_DIGITAL_H
#define UNOLIB_DIGITAL_H

enum mode {
    OUTPUT,
    INPUT
};

enum voltage {
    HIGH,
    LOW
};

static const uint8_t MIN_PORTD_PIN = 0;
static const uint8_t MAX_PORTD_PIN = 7;
static const uint8_t MIN_PORTB_PIN = 8;
static const uint8_t MAX_PORTB_PIN = 13;

// Aliases for analog pins.
#define A0 14
#define A1 15
#define A2 16
#define A3 17
#define A4 18
#define A5 19

static const uint8_t MIN_ANALOG_ALIAS = A0;
static const uint8_t MAX_ANALOG_ALIAS = A5;

/**
 * Sets the pin mode to be input or output.
 * @param pin Pin number
 * @param mode Input or output
 */
void pin_mode(uint8_t pin, enum mode m);

/**
 * Sends HIGH or LOW volatage to a pin. This expects the pin to be in output
 * mode.
 * @param pin Pin number
 * @parma w HIGH or LOW
 */
void digital_write(uint8_t pin, enum voltage w);

/**
 * Toggles between HIGH and LOW for a specified pin.
 * @param pin Pin number
 */
void digital_toggle(uint8_t pin);

/**
 * Read voltage from a pin.
 * @param  pin Pin number
 * @return     HIGH or LOW
 */
enum voltage digital_read(uint8_t pin);

#endif
