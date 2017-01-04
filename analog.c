#include <avr/io.h>
#include <inttypes.h>

#include "analog.h"
#include "pins.h"

void analog_write(uint8_t pin, uint8_t val) {
    enum timer_id timer = pin_to_timer(pin);

    // Phase correct pwm
    switch (timer) {
        case T0A:
            TCCR0A |= _BV(COM0A1) | _BV(WGM00);
            TCCR0B |= _BV(CS00);
            OCR0A = val;
            break;
        case T0B:
            TCCR0A |= _BV(COM0B1) | _BV(WGM00);
            TCCR0B |= _BV(CS00);
            OCR0B = val;
            break;
        case T1A:
            TCCR1A |= _BV(COM1A1) | _BV(WGM10);
            TCCR1B |= _BV(CS10);
            OCR1A = val;
            break;
        case T1B:
            TCCR1A |= _BV(COM1B1) | _BV(WGM10);
            TCCR1B |= _BV(CS10);
            OCR1B = val;
            break;
        case T2A:
            TCCR2A |= _BV(COM2A1) | _BV(WGM20);
            TCCR2B |= _BV(CS20);
            OCR2A = val;
            break;
        case T2B:
            TCCR2A |= _BV(COM2B1) | _BV(WGM20);
            TCCR2B |= _BV(CS20);
            OCR2B = val;
            break;
        case NOT_A_TIMER:
            break;
    }
}

uint16_t analog_read(uint8_t pin) {
    ADCSRA |= _BV(ADPS2) | _BV(ADPS1) | _BV(ADPS0);

    ADMUX = 0; // Reset which pin is selected
    ADMUX |= _BV(REFS0); // Reference AVCC

    switch (pin) {
        case A0:
            // Nothing needed, ADC0 is default
            break;
        case A1:
            ADMUX |= _BV(MUX0);
            break;
        case A2:
            ADMUX |= _BV(MUX1);
            break;
        case A3:
            ADMUX |= _BV(MUX1) | _BV(MUX0);
            break;
        case A4:
            ADMUX |= _BV(MUX2);
            break;
        case A5:
            ADMUX |= _BV(MUX2) | _BV(MUX0);
            break;
    }

    ADCSRA |= _BV(ADIE); // Enable interrupts
    ADCSRA |= _BV(ADEN); // Enable ADC

    ADCSRA |= _BV(ADSC); // Start analog to digital conversion

    uint8_t low = ADCL;
    uint8_t high = ADCH;

    uint16_t result = (high << 8) | low;

    return result;
}
