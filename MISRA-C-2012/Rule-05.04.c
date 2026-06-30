#include <stdint.h>

/**
 * Compliance Check: MISRA C:2012 Rule 5.4
 * Rule: Macro identifiers shall be distinct.
 */

/* --- NON-COMPLIANT --- */
/* Violation: Redefining the same macro in different contexts or files
   can lead to unpredictable behavior because macros have no scope. */

#define TIMEOUT_VAL 100U  /* Defined in module_a.h */

void macro_collision_bad(void) {
    /* ... some code ... */
}

#define TIMEOUT_VAL 500U  /* Violation: Redefinition of TIMEOUT_VAL */

/* The value used depends on the preprocessor's order of inclusion,
   which is prone to errors. */


/* --- MISRA COMPLIANT --- */
/* Compliant: Use descriptive prefixes to ensure uniqueness 
   and avoid collisions across the entire project. */

#define MODULE_A_TIMEOUT_VAL 100U
#define MODULE_B_TIMEOUT_VAL 500U

void macro_distinct_good(void) {
    uint16_t timer_a = MODULE_A_TIMEOUT_VAL;
    uint16_t timer_b = MODULE_B_TIMEOUT_VAL;
}