#ifndef UNOLIB_SERIAL_H
#define UNOLIB_SERIAL_H

/**
 * Readies the device for serial io.
 */
void serial_init(void);

/**
 * Optionally set the input and output for a pair of file streams. E.g. stdout
 * and stdin can be used so built in stdio functions can be used.
 * @param output Output file stream pointer
 * @param input  Input file stream pointer
 */
void serial_set(FILE **output, FILE **input);

/**
 * Serial input and output streams.
 */
extern FILE serial_out;
extern FILE serial_in;

#endif
