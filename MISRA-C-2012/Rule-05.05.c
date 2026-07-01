#include <stdint.h>

/**
 * Compliance Check: MISRA C:2012 Rule 5.5
 * Rule: Identifiers shall be distinct from macro names.
 */

/* --- NON-COMPLIANT --- */
/* Violation: The macro and the variable share the same identifier name. 
   This causes ambiguity and potential errors during pre-processing. */
#define BUFFER_SIZE 64U

void name_collision_bad(void) {
    /* Violation: Identifier 'BUFFER_SIZE' conflicts with the macro name */
    uint16_t BUFFER_SIZE = 10U; 
}

/* --- MISRA COMPLIANT --- */
/* Compliant: Macro names and identifiers are distinct, 
   ensuring the code is unambiguous for both the preprocessor and the compiler. */
#define BUFFER_SIZE_MAX 64U

void name_distinct_good(void) {
    uint16_t current_buffer_size = 10U;
}