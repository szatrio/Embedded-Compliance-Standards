#include <stdint.h>

/**
 * Compliance Check: MISRA C:2012 Rule 5.6
 * Rule: A typedef name shall be a unique identifier.
 */

/* --- NON-COMPLIANT --- */
/* Violation: 'status' is used as a variable name and a typedef name 
   in the same namespace, creating ambiguity. */

typedef uint8_t status; /* The type alias */

void typedef_collision_bad(void) {
    status current_status = 0U; /* Which one is 'status'? The type or the variable? */
    uint8_t status = 1U;        /* Violation: redeclaring 'status' */
}

/* --- MISRA COMPLIANT --- */
/* Compliant: Use a distinct naming convention (e.g., '_t' suffix) 
   to clearly distinguish types from variables. */

typedef uint8_t status_t; /* Clear: this is a type */

void typedef_distinct_good(void) {
    status_t current_status = 0U; /* No ambiguity */
}