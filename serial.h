#ifndef UNOLIB_SERIAL_H
#define UNOLIB_SERIAL_H

/**
 * Readies the device for serial io.
 */
void serial_init(void);

/**
 * Serial input and output streams. 
 */
extern FILE serial_out;
extern FILE serial_in;

#endif
