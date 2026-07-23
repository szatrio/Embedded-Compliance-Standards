#include <stdint.h>

/**
 * Compliance Check: MISRA C:2012 Rule 10.4
 * Rule: Both operands of an operator in which the usual arithmetic conversions
 * are performed shall have the same essential type category.
 */

void rule_10_4_demo(void)
{
    uint16_t u16_val = 100U;
    int16_t  s16_val = -20;
    uint16_t result;

    /* --- NON-COMPLIANT --- */
    /* Violation: Mixing Unsigned (u16_val) and Signed (s16_val) essential type categories */
    result = u16_val + s16_val;

    /* Violation: Comparing Unsigned variable with Signed literal (5 is signed int) */
    if (u16_val > 5)
    {
        /* ... */
    }

    /* --- MISRA COMPLIANT --- */
    /* Compliant: Explicit cast converts s16_val to Unsigned category before addition */
    result = u16_val + (uint16_t)s16_val;

    /* Compliant: Both operands are Unsigned essential type category (using 'U' suffix) */
    if (u16_val > 5U)
    {
        /* ... */
    }
}