#include <stdint.h>
#include <stddef.h>

/**
 * Compliance Check: MISRA C:2012 Rule 21.1
 * Rule: #define and #undef shall not be used on a reserved identifier 
 * or a macro name defined in a standard library.
 */

/* --- NON-COMPLIANT --- */
/* Redefining standard keywords or reserved macros completely breaks compiler 
   portability and causes unpredictable behavior across different translation units. */
/* #define NULL ((void *)0x1234) */
/* #define inline */


/* --- MISRA COMPLIANT --- */
/* Use unique, project-specific prefixes to ensure no collision with 
   any standard library keywords or definitions. */
#define APPLICATION_NULL_POINTER    ((void *)0)

void test_compliance_21_1(void) {
    uint8_t *buffer_ptr = APPLICATION_NULL_POINTER;
    
    if (buffer_ptr == NULL) {
        /* Standard NULL behaves exactly as defined by <stddef.h> */
        buffer_ptr = NULL;
    }
}
