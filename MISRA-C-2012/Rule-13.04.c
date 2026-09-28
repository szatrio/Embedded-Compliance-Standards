#include <stdint.h>
#include <stdbool.h>

/**
 * Compliance Check: MISRA C:2012 Rule 13.4
 * Rule: The result of an assignment operator should not be used.
 */

/* External function declaration */
extern uint32_t read_sensor(void);

/* --- NON-COMPLIANT EXAMPLES --- */

void assignment_result_bad(void)
{
    uint32_t a;
    uint32_t b;
    uint32_t c;

    /* Non-compliant: Chained assignments use the result of assignment */
    a = b = c = 0U;

    /* Non-compliant: Assignment used inside an 'if' condition (common typo bug) */
    if ((a = read_sensor()) > 10U)
    {
        /* ... */
    }
}


/* --- MISRA COMPLIANT EXAMPLES --- */

void assignment_result_good(void)
{
    uint32_t a;
    uint32_t b;
    uint32_t c;

    /* Compliant: Separate assignment statements */
    c = 0U;
    b = 0U;
    a = 0U;

    /* Compliant: Assignment evaluated prior to using value in condition */
    a = read_sensor();
    if (a > 10U)
    {
        /* ... */
    }
}