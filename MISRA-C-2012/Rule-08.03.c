#include <stdint.h>

/**
 * Compliance Check: MISRA C:2012 Rule 8.3
 * Rule: All declarations of an object or function shall use the same 
 * names and type qualifiers.
 */

/* --- DECLARATION (in header file) --- */
void process_data(const uint8_t *buffer, uint16_t length);

/* --- NON-COMPLIANT --- */
/* Violation: Parameter name 'len' differs from the declaration 'length'.
   Also, missing the 'const' qualifier. */
void process_data(uint8_t *buffer, uint16_t len) {
    /* ... */
}

/* --- MISRA COMPLIANT --- */
/* Compliant: Parameter names and type qualifiers match the declaration exactly */
void process_data(const uint8_t *buffer, uint16_t length) {
    /* Implementation matches the header declaration perfectly */
}