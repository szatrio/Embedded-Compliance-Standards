#include <stdint.h>

/**
 * Compliance Check: MISRA C:2012 Rule 6.2
 * Rule: Single-bit named bit fields shall not be of a signed type.
 */

/* --- NON-COMPLIANT --- */
struct status_bad {
    /* Violation: 'signed int' of 1-bit width creates sign-bit ambiguity */
    signed int is_active : 1; 
};

/* --- MISRA COMPLIANT --- */
struct status_good {
    /* Compliant: 'unsigned int' or 'bool' ensures values are 0 or 1 */
    unsigned int is_active : 1;
};