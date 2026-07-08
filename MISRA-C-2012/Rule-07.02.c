#include <stdint.h>

/**
 * Compliance Check: MISRA C:2012 Rule 7.2
 * Rule: A “u” or “U” suffix shall be applied to all integer constants 
 * that are represented in an unsigned type.
 */

/* --- NON-COMPLIANT --- */
void unsigned_const_bad(void) {
    /* Violation: The constant 100 lacks the 'U' suffix. 
       Even though it is syntactically valid in C, MISRA requires 
       explicit type tagging for unsigned constants. */
    uint16_t val = 100; 

    /* Violation: Masking performed using a constant without the required suffix */
    uint32_t mask = 0xFF00; 
}

/* --- MISRA COMPLIANT --- */
void unsigned_const_good(void) {
    /* Compliant: Using the 'U' suffix to explicitly define the constant as unsigned */
    uint16_t val = 100U;

    /* Compliant: Using the 'U' suffix for hexadecimal constants */
    uint32_t mask = 0xFF00U;
    
    /* Example within a conditional operation */
    if (val < 200U) {
        /* Operation is compliant as constants are properly suffixed */
    }
}