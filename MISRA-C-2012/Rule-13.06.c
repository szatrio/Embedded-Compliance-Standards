#include <stdint.h>
#include <stdio.h>

/**
 * Compliance Check: MISRA C:2012 Rule 13.6
 * Rule: The operand of the sizeof operator shall not contain any expression 
 * which has potential side effects.
 */

/* --- NON-COMPLIANT --- */
/* The expression 'x++' is a side effect. */
void sizeof_side_effect_bad(void) {
    uint16_t x = 10U;
    size_t size;

    /* Violation: 'x++' will NEVER execute at runtime. 
       'x' remains 10, but the developer might wrongly expect it to become 11. */
    size = sizeof(x++); 
}

/* --- MISRA COMPLIANT --- */
/* Use sizeof only for types or objects without modifying them. */
void sizeof_side_effect_good(void) {
    uint16_t x = 10U;
    size_t size;

    /* Compliant: No side effects here. */
    size = sizeof(x); 
    
    /* If you really need to increment, do it outside of sizeof. */
    x++;
}