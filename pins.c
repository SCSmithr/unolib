#include <inttypes.h>

#include <avr/io.h>

#include "pins.h"

static const uint8_t MIN_PORTD_PIN = 0;
static const uint8_t MAX_PORTD_PIN = 7;
static const uint8_t MIN_PORTB_PIN = 8;
static const uint8_t MAX_PORTB_PIN = 13;

static const uint8_t MIN_ANALOG_ALIAS = 14; // A0
static const uint8_t MAX_ANALOG_ALIAS = 19; // A5

volatile uint8_t* port_to_ddr_mapping[] = {
    &DDRD,
    &DDRC,
    &DDRB,
};

volatile uint8_t* port_to_data_mapping[] = {
    &PORTD,
    &PORTC,
    &PORTB,
};

volatile uint8_t* port_to_input_mapping[] = {
    &PIND,
    &PINC,
    &PINB,
};

uint8_t pin_to_bit_mask(uint8_t pin) {
    uint8_t port_pin;
    if (pin >= MIN_PORTD_PIN && pin <= MAX_PORTD_PIN) {
        port_pin = _BV(pin);
    } else if (pin >= MIN_PORTB_PIN && pin <= MAX_PORTB_PIN) {
        port_pin = _BV(pin - 8);
    } else if (pin >= MIN_ANALOG_ALIAS && pin <= MAX_ANALOG_ALIAS) {
        port_pin = _BV(pin -14);
    } else {
        port_pin = NO_PIN;
    }

    return port_pin;
}

enum port_index pin_to_port(uint8_t pin) {
    enum port_index port_alias;
    if (pin >= MIN_PORTD_PIN && pin <= MAX_PORTD_PIN) {
        port_alias = PD;
    } else if (pin >= MIN_PORTB_PIN && pin <= MAX_PORTB_PIN) {
        port_alias = PB;
    } else if (pin >= MIN_ANALOG_ALIAS && pin <= MAX_ANALOG_ALIAS) {
        port_alias = PC;
    } else {
        port_alias = NO_PORT;
    }

    return port_alias;
}

enum timer_id pin_to_timer(uint8_t pin) {
    enum timer_id timer_alias;
    switch (pin) {
        case 3:
            timer_alias = T2B;
            break;
        case 5:
            timer_alias = T0B;
            break;
        case 6:
            timer_alias = T0A;
            break;
        case 9:
            timer_alias = T1A;
            break;
        case 10:
            timer_alias = T1B;
            break;
        case 11:
            timer_alias = T2A;
            break;
        default:
            timer_alias = NO_PWM;
    }

    return timer_alias;
}
