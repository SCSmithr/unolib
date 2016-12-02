#include <inttypes.h>
#include <avr/io.h>

#include "digital.h"

// Pin mode
static void digital_pin_output(uint8_t pin);
static void digital_pin_input(uint8_t pin);

// Pin write
static void digital_pin_high(uint8_t pin);
static void digital_pin_low(uint8_t pin);

void pin_mode(uint8_t pin, enum mode m) {
    if (m == OUTPUT) {
        digital_pin_output(pin);
    } else {
        digital_pin_input(pin);
    }
}

void digital_write(uint8_t pin, enum voltage w) {
    if (w == HIGH) {
        digital_pin_high(pin);
    } else {
        digital_pin_low(pin);
    }
}

void digital_toggle(uint8_t pin) {
    if (pin >= MIN_PORTD_PIN && pin <= MAX_PORTD_PIN) {
        PORTD ^= _BV(pin);
    } else if (pin >= MIN_PORTB_PIN && pin <= MAX_PORTB_PIN) {
        pin = pin - 8;
        PORTB ^=  _BV(pin);
    }
}

enum voltage digital_read(uint8_t pin) {
    uint8_t val;
    if (pin >= MIN_PORTD_PIN && pin <= MAX_PORTD_PIN) {
        val = PIND & _BV(pin);
    } else if (pin >= MIN_PORTB_PIN && pin <= MAX_PORTB_PIN) {
        pin = pin - 8;
        val = PINB & _BV(pin);
    }

    enum voltage v = LOW;
    if (val) {
        v = HIGH;
    }

    return v;
}

static void digital_pin_output(uint8_t pin) {
    if (pin >= MIN_PORTD_PIN && pin <= MAX_PORTD_PIN) {
        DDRD |= _BV(pin);
    } else if (pin >= MIN_PORTB_PIN && pin <= MAX_PORTB_PIN) {
        pin = pin - 8; // Pin 8 is first pin on port b.
        DDRB |= _BV(pin);
    }
}

static void digital_pin_input(uint8_t pin) {
    if (pin >= MIN_PORTD_PIN && pin <= MAX_PORTD_PIN) {
        DDRD &= ~(_BV(pin));
    } else if (pin >= MIN_PORTB_PIN && pin <= MAX_PORTB_PIN) {
        pin = pin - 8;
        DDRB &= ~(_BV(pin));
    }
}

static void digital_pin_high(uint8_t pin) {
    if (pin >= MIN_PORTD_PIN && pin <= MAX_PORTD_PIN) {// Pin 8 is first pin on port b.
        PORTD |= _BV(pin);
    } else if (pin >= MIN_PORTB_PIN && pin <= MAX_PORTB_PIN) {
        pin = pin - 8;
        PORTB |= _BV(pin);
    }
}

static void digital_pin_low(uint8_t pin) {
     if (pin >= MIN_PORTD_PIN && pin <= MAX_PORTD_PIN) {
        PORTD &= ~_BV(pin);
    } else if (pin >= MIN_PORTB_PIN && pin <= MAX_PORTB_PIN) {
        pin = pin - 8;
        PORTB &= ~_BV(pin);
    }

}
