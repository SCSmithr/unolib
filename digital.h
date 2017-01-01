#ifndef UNOLIB_DIGITAL_H
#define UNOLIB_DIGITAL_H

enum mode {
    OUTPUT,
    INPUT,
    INPUT_PULLUP
};

enum voltage {
    HIGH,
    LOW
};

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
