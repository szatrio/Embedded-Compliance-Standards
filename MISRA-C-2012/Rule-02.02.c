#include <stdint.h>

/**
 * Compliance Check: MISRA C:2012 Rule 2.2
 * Rule: There shall be no dead code.
 */

/* --- NON-COMPLIANT --- */
/* The code after 'return' will never be reached. */
uint16_t calculate_data_bad(uint16_t input) {
    uint16_t result = input * 2U;
    
    return result;

    /* Violation: This code is unreachable (dead code). */
    result = result + 10U; 
    return result;
}

/* --- MISRA COMPLIANT --- */
/* Remove unreachable code to ensure every line serves a purpose. */
uint16_t calculate_data_good(uint16_t input) {
    uint16_t result = input * 2U;
    
    /* Compliant: All code is reachable and meaningful. */
    result = result + 10U; 
    return result;
}