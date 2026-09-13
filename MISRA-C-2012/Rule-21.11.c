#include <stdint.h>
#include <math.h>

/**
 * Compliance Check: MISRA C:2012 Rule 21.11
 * Rule: The standard header file <tgmath.h> shall not be used.
 */

/* --- NON-COMPLIANT EXAMPLE --- */

/* Non-compliant: Including <tgmath.h> and using generic math macros */
/*
#include <tgmath.h>

void test_rule_21_11_bad(void)
{
    float f1 = 16.0f;
    float result = sqrt(f1); // Non-compliant: generic macro selection
    (void)result;
}
*/


/* --- MISRA COMPLIANT EXAMPLE --- */

void test_rule_21_11_good(void)
{
    float f_val = 16.0f;
    double d_val = 25.0;

    /* Compliant: Use type-explicit function sqrtf() for float */
    float f_result = sqrtf(f_val);

    /* Compliant: Use type-explicit function sqrt() for double */
    double d_result = sqrt(d_val);

    (void)f_result;
    (void)d_result;
}