#include <stdint.h>

/**
 * Compliance Check: MISRA C:2012 Rule 7.1
 * Rule: Octal constants shall not be used.
 */

/* --- NON-COMPLIANT --- */
void octal_bad(void) {
    /* Violation: 010 is interpreted as 8 (octal), not 10 (decimal). */
    uint16_t value = 010; 
}

/* --- MISRA COMPLIANT --- */
void octal_good(void) {
    /* Compliant: Use standard decimal for normal numbers */
    uint16_t value = 10U;

    /* Compliant: Use hexadecimal if you are dealing with hardware registers/masks */
    uint16_t mask = 0x0A; 
}