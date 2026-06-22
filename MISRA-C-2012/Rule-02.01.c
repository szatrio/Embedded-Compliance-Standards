#include <stdint.h>

/**
 * Compliance Check: MISRA C:2012 Rule 2.1
 * Rule: A project shall not contain unreachable code.
 */

/* --- NON-COMPLIANT --- */
/* The block inside the 'if' condition can never be executed. */
void unreachable_logic_bad(uint16_t x) {
    if (x > 100U) {
        /* ... some code ... */
    } else if (x > 200U) { 
        /* Violation: This branch is unreachable because if x > 200, 
           the first condition (x > 100) would have already caught it. */
        do_something_critical(); 
    }
}

/* --- MISRA COMPLIANT --- */
/* Ensure logical conditions are reachable and non-overlapping. */
void reachable_logic_good(uint16_t x) {
    if (x > 200U) {
        do_something_critical();
    } else if (x > 100U) {
        /* This is now reachable and logically sound. */
        do_something_else();
    }
}