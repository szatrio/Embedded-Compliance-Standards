#include <stdint.h>

/**
 * Compliance Check: MISRA C:2012 Rule 9.1
 * Rule: The value of an object with automatic storage duration 
 * shall not be read before it has been set.
 */

/* --- NON-COMPLIANT --- */
/* 'x' is read before it is assigned any value. */
void read_unitialized_bad(void) {
    uint16_t x;
    uint16_t result;

    /* Violation: 'x' contains garbage value. Reading it results 
       in undefined behavior. */
    result = x + 10U; 
}

/* --- MISRA COMPLIANT --- */
/* Always initialize variables at the point of declaration or 
   immediately before usage. */
void read_unitialized_good(void) {
    /* Compliant: Explicitly initialized to 0 or a known value. */
    uint16_t x = 0U; 
    uint16_t result;

    result = x + 10U;
}