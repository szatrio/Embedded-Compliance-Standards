#include <stdint.h>

/**
 * Compliance Check: MISRA C:2012 Rule 12.3
 * Rule: The comma operator should not be used.
 */

/* External function declaration */
extern void process_values(uint32_t a, uint32_t b);

/* --- NON-COMPLIANT EXAMPLES --- */

void comma_operator_bad(uint32_t x, uint32_t y)
{
    uint32_t a;
    uint32_t b;

    /* Non-compliant: Comma operator used in expression assignment */
    a = (x++, y + 1U);

    /* Non-compliant: Comma operator used inside loop header */
    for (a = 0U, b = 10U; a < b; a++, b--)
    {
        /* ... */
    }
}


/* --- MISRA COMPLIANT EXAMPLES --- */

void comma_operator_good(uint32_t x, uint32_t y)
{
    uint32_t a;
    uint32_t b;

    /* Compliant: Split into separate, clear statements */
    x++;
    a = y + 1U;

    /* Compliant: Separate initialization and loop step statements */
    a = 0U;
    b = 10U;
    while (a < b)
    {
        /* Loop operations */
        a++;
        b--;
    }

    /* Compliant: Comma used as function argument separator (NOT a comma operator) */
    process_values(a, b);
}