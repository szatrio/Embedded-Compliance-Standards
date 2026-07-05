#include <stdint.h>
#include <stdbool.h>

/**
 * Compliance Check: MISRA C:2012 Rule 6.1
 * Rule: Bit-fields shall only be declared with an appropriate type.
 */

/* --- NON-COMPLIANT --- */
/* Violation: Using 'char' or other non-standard types for bit-fields 
   is implementation-defined and dangerous for portability. */
struct sensor_data_bad {
    char status : 1;      /* Violation: 'char' is not an appropriate type */
    uint8_t value : 7;    /* Violation: 'uint8_t' might not be allowed as bit-field type */
};

/* --- MISRA COMPLIANT --- */
/* Compliant: Using 'unsigned int' or 'bool' ensures consistent 
   behavior across different compilers. */
struct sensor_data_good {
    bool is_active : 1;             /* Compliant: bool */
    unsigned int status : 3;        /* Compliant: unsigned int */
    unsigned int error_code : 4;    /* Compliant: unsigned int */
};