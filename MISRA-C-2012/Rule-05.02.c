#include <stdint.h>

/**
 * Compliance Check: MISRA C:2012 Rule 5.2
 * Rule: Identifiers declared in the same scope and name space shall be distinct.
 */

/* --- NON-COMPLIANT --- */
void shadowing_example_bad(void) {
    uint16_t counter = 0U;

    if (counter < 10U) {
        /* Violation: 'counter' declared again in inner scope. 
           It hides the 'counter' from the outer scope! */
        uint16_t counter = 5U; 
        
        /* 'counter' here refers to the inner one (5), 
           causing confusion and potential logic errors. */
    }
}

/* --- MISRA COMPLIANT --- */
void shadowing_example_good(void) {
    uint16_t outer_counter = 0U;

    if (outer_counter < 10U) {
        /* Compliant: Name is distinct, no shadowing occurs. */
        uint16_t inner_counter = 5U;
        
        outer_counter = inner_counter;
    }
}