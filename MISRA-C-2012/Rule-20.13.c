#include <stdint.h>

/**
 * Compliance Check: MISRA C:2012 Rule 20.13
 * Rule: A line whose first token is # shall be a valid preprocessing directive.
 */

#define AAA 2

/* --- NON-COMPLIANT EXAMPLE --- */

int32_t foo_bad(void)
{
    int32_t x = 0;

#ifndef AAA
    x = 1;
#else1        /* Non-compliant: '#else1' is not a valid preprocessing directive */
    x = AAA;
#endif

    return x;
}

/* --- MISRA COMPLIANT EXAMPLES --- */

int32_t foo_good(void)
{
    int32_t x = 0;

/* Compliant: White-space between # and directive is allowed */
#  ifndef AAA
    x = 1;
#  else       /* Compliant: '#else' is a valid preprocessing directive */
    x = AAA;
#  endif

    /* Compliant: #start inside a comment is ignored because it is not a token */
    /* #start is not a token in a comment */

    return x;
}