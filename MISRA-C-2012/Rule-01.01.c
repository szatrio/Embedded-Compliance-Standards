#include <stdint.h>

/**
 * Compliance Check: MISRA C:2012 Rule 1.1
 * Rule: The program shall contain no violations of the standard C syntax 
 * and constraints, and shall not exceed implementation translation limits.
 */

/* --- NON-COMPLIANT --- */
/* Syntax Violation: Declaring variables in the middle of a function 
   is prohibited in C90/ANSI C, which is often used in embedded systems. */
void invalid_syntax_bad(void) {
    uint16_t x = 10U;
    x++;
    /* Violation: Variable declaration after a statement is not allowed in C90. */
    uint16_t y = 20U; 
}

/* --- MISRA COMPLIANT --- */
/* All variables are declared at the beginning of the scope, 
   ensuring compatibility with strict C standards and improving code readability. */
void valid_syntax_good(void) {
    uint16_t x = 10U;
    uint16_t y = 20U;
    
    x++;
    y++;
}