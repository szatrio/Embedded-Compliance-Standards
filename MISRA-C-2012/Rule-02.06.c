#include <stdint.h>

/**
 * Compliance Check: MISRA C:2012 Rule 2.6
 * Rule: A function should not contain unused label declarations.
 */

/* External function declaration */
extern void use_int16(int16_t val);

/* --- NON-COMPLIANT EXAMPLE --- */

void unused_label_bad(void)
{
    int16_t x = 6;

label1: /* Non-compliant: label1 is declared but never referenced by any goto */[cite: 1]
    use_int16(x);[cite: 1]
}


/* --- MISRA COMPLIANT EXAMPLES --- */

/* Compliant Example 1: Remove the unused label completely */
void unused_label_good(void)
{
    int16_t x = 6;

    use_int16(x);
}

/* Compliant Example 2: The label is declared and explicitly used as a goto target */
void label_used_good(int16_t status)
{
    if (status < 0)
    {
        goto error_cleanup; /* Compliant: Label is referenced */
    }

    use_int16(status);
    return;

error_cleanup:
    use_int16(-1);
}