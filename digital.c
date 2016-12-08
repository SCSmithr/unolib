#include <inttypes.h>
#include <avr/io.h>

#include "digital.h"

enum register_type {
    DDR,
    PIN,
    PORT
};

enum register_group {
    B,
    C,
    D
};


static volatile uint8_t* get_ddr_for_group(enum register_group group);
static volatile uint8_t* get_pin_for_group(enum register_group group);
static volatile uint8_t* get_port_for_group(enum register_group group);

static volatile uint8_t* get_register(enum register_type type, enum register_group group);

static enum register_group group_for_pin(uint8_t pin);

static uint8_t get_port_pin_number(uint8_t pin);

static void set(volatile uint8_t *reg, uint8_t pin);

static void unset(volatile uint8_t *reg, uint8_t pin);

static void toggle(volatile uint8_t *reg, uint8_t pin);

static uint8_t read(volatile uint8_t *reg, uint8_t pin);

void pin_mode(uint8_t pin, enum mode m) {
    volatile uint8_t *ddr = get_register(DDR, group_for_pin(pin));
    if (m == OUTPUT) {
        set(ddr, pin);
    } else {
        unset(ddr, pin);
    }
}

void digital_write(uint8_t pin, enum voltage w) {
    volatile uint8_t *port = get_register(PORT, group_for_pin(pin));
    if (w == HIGH) {
        set(port, pin);
    } else {
        unset(port, pin);
    }
}

void digital_toggle(uint8_t pin) {
    volatile uint8_t *port = get_register(PORT, group_for_pin(pin));
    toggle(port, pin);
}

enum voltage digital_read(uint8_t pin) {
    volatile uint8_t *pin_reg = get_register(PIN, group_for_pin(pin));
    uint8_t val = read(pin_reg, pin);

    enum voltage v = LOW;
    if (val) {
        v = HIGH;
    }

    return v;
}

/*
 * Static functions
 */

static volatile uint8_t* get_ddr_for_group(enum register_group group) {
    volatile uint8_t *ddr;
    if (group == B) {
        ddr = &DDRB;
    } else if (group == C) {
        ddr = &DDRC;
    } else if (group == D) {
        ddr = &DDRD;
    }

    return ddr;
}

static volatile uint8_t* get_pin_for_group(enum register_group group) {
    volatile uint8_t *pin;
    if (group == B) {
        pin = &PINB;
    } else if (group == C) {
        pin = &PINC;
    } else if (group == D) {
        pin = &PIND;
    }

    return pin;
}

static volatile uint8_t* get_port_for_group(enum register_group group) {
    volatile uint8_t *port;
    if (group == B) {
        port = &PORTB;
    } else if (group == C) {
        port = &PORTC;
    } else if (group == D) {
        port = &PORTD;
    }

    return port;
}

static volatile uint8_t* get_register(enum register_type type, enum register_group group) {
    volatile uint8_t *reg;
    if (type == DDR) {
        reg = get_ddr_for_group(group);
    } else if (type == PIN) {
        reg = get_pin_for_group(group);
    } else if (type == PORT) {
        reg = get_port_for_group(group);
    }

    return reg;
}

static enum register_group group_for_pin(uint8_t pin) {
    enum register_group group;
    if (pin >= MIN_PORTB_PIN && pin <= MAX_PORTB_PIN) {
        group = B;
    } else if (pin >= MIN_ANALOG_ALIAS && pin <= MAX_ANALOG_ALIAS) {
        group = C;
    } else {
        group = D;
    }

    return group;
}

static uint8_t get_port_pin_number(uint8_t pin) {
    if (pin >= MIN_PORTB_PIN && pin <= MAX_PORTB_PIN) {
        pin = pin - 8;
    } else if (pin >= MIN_ANALOG_ALIAS && pin <= MAX_ANALOG_ALIAS) {
        pin = pin - 14;
    }

    return pin;
}

static void set(volatile uint8_t *reg, uint8_t pin) {
    uint8_t port_pin = get_port_pin_number(pin);
    *reg |= _BV(port_pin);
}

static void unset(volatile uint8_t *reg, uint8_t pin) {
    uint8_t port_pin = get_port_pin_number(pin);
    *reg &= ~(_BV(port_pin));
}

static void toggle(volatile uint8_t *reg, uint8_t pin) {
    uint8_t port_pin = get_port_pin_number(pin);
    *reg ^= _BV(port_pin);
}

static uint8_t read(volatile uint8_t *reg, uint8_t pin) {
    uint8_t port_pin = get_port_pin_number(pin);
    uint8_t val = *reg & _BV(port_pin);
    return val;
}
