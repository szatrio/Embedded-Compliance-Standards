#include <stdint.h>

/**
 * Compliance Check: MISRA C:2012 Rule 8.10
 * Rule: An inline function shall be declared with the static storage class.
 */

/* --- NON-COMPLIANT --- */

/* Violation: Inline function declared without 'static'. 
   Can lead to undefined behavior or multiple definition errors during linking. */
inline uint32_t standard_square(uint32_t val) { /* Violation: Missing 'static' */
    return val * val;
}

/* --- MISRA COMPLIANT --- */

/* Compliant: Inline function explicitly declared with 'static'.
   Ensures the function definition is self-contained within the translation unit. */
static inline uint32_t compliant_square(uint32_t val) { /* Compliant: Using 'static inline' */
    return val * val;
}