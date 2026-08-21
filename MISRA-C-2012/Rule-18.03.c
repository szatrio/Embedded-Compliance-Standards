#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

/**
 * Compliance Check: MISRA C:2012 Rule 18.3
 * Rule: The relational operators >, >=, < and <= shall not be applied to objects of pointer type except where they point into the same object.
 */

/* Non-compliant example */
void test_rule_18_3_bad(void)
{
    uint32_t a = 10U;
    uint32_t b = 20U;

    uint32_t *p1 = &a;
    uint32_t *p2 = &b;

    /* Non-compliant: p1 and p2 point to different objects */
    if (p1 < p2)
    {
        /* Code execution */
    }
}

/* Compliant example */
void test_rule_18_3_good(void)
{
    uint32_t array[10] = {0U};

    uint32_t *ptr1 = &array[2];
    uint32_t *ptr2 = &array[5];

    /* Compliant: ptr1 and ptr2 point to elements of the same array */
    if (ptr1 < ptr2)
    {
        /* Code execution */
    }
}