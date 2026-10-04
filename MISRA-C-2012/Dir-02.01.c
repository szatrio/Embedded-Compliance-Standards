#include <stdint.h>

/**
 * Compliance Check: MISRA C:2012 Directive 2.1
 * Directive: All source files shall compile without any compilation errors.
 */

/* --- NON-COMPLIANT EXAMPLES --- */

/* Non-compliant: Invalid syntax or unrecognized extension causing compilation failure */
void process_data_bad(void)
{
    /* Non-compliant: Syntax error due to missing semicolon or invalid keyword */
    uint32_t val = 10U
    (void)val;
}

/* Non-compliant: Conditional compilation block producing an invalid preprocessing directive */
#if defined(ENABLE_FEATURE)
    #error_custom "Feature is not supported on this target" /* Syntax error: Invalid directive */
#endif


/* --- MISRA COMPLIANT EXAMPLES --- */

/* Compliant: Pure standard C code that compiles cleanly on any standard C compiler */
void process_data_good(void)
{
    /* Compliant: Proper variable declaration and standard syntax */
    uint32_t val = 10U;
    (void)val;
}

/* Compliant: Proper conditional compilation using standard directives */
#if defined(ENABLE_FEATURE)
    #error "Feature is not supported on this target" /* Valid standard preprocessor error directive */
#endif