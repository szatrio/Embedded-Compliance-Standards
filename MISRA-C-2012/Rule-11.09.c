#include <stdint.h>
#include <stddef.h> /* Standard header defining NULL macro */

/* --- NON-COMPLIANT --- */

void non_compliant_demo(void)
{
    uint32_t *ptr1 = 0;    /* Violation: 0 used as null pointer constant */
    uint32_t *ptr2 = 0U;   /* Violation: 0U used as null pointer constant */

    if (ptr1 == 0)         /* Violation: Comparison against literal 0 */
    {
        /* Error handling */
    }
}

/* --- MISRA COMPLIANT --- */

void compliant_demo(void)
{
    uint32_t *ptr1 = NULL; /* Compliant: NULL macro explicitly used */
    uint32_t *ptr2 = NULL; /* Compliant */

    if (ptr1 == NULL)      /* Compliant: Explicitly checked against NULL */
    {
        /* Error handling */
    }
}