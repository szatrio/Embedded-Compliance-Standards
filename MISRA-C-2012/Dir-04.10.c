/**
 * Compliance Check: MISRA C:2012 Directive 4.10
 * Directive: Precautions shall be taken in order to prevent the contents of
 *            a header file being included more than once.
 */

/* --- NON-COMPLIANT EXAMPLE (sensor_bad.h) --- */

/* Non-compliant: Header file lacks include guards, leading to redefinition errors if included twice */
#include <stdint.h>

void sensor_init_bad(void);
uint32_t sensor_read_bad(void);


/* --- MISRA COMPLIANT EXAMPLES (sensor_good.h) --- */

/* Compliant: Standard C include guard prevents multiple inclusions */
#ifndef SENSOR_GOOD_H
#define SENSOR_GOOD_H

#include <stdint.h>

void sensor_init_good(void);
uint32_t sensor_read_good(void);

#endif /* SENSOR_GOOD_H */