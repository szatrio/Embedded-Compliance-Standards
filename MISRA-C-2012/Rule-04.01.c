#include <stdint.h>

/**
 * Compliance Check: MISRA C:2012 Rule 4.1
 * Rule: Octal and hexadecimal escape sequences shall be terminated.
 */

/* --- NON-COMPLIANT --- */
/* The compiler might treat the next digits as part of the escape sequence. */
void escape_sequence_bad(void) {
    /* Violation: Is this char '\x41' followed by '5', or is it '\x415'? 
       It is ambiguous to the compiler! */
    char *str = "\x415"; 
}

/* --- MISRA COMPLIANT --- */
/* Use string concatenation or explicit formatting to terminate sequences. */
void escape_sequence_good(void) {
    /* Compliant: '\x41' is clearly defined, and '5' is a separate character. */
    char *str = "\x41" "5"; 
}