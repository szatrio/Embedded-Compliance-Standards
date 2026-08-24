#include <stdint.h>
#include <stddef.h>

/**
 * Compliance Check: MISRA C:2012 Rule 18.8
 * Rule: Variable-length array types shall not be used.
 */

#define MAX_SIZE 10U

/* Non-compliant example */
void test_rule_18_8_bad(uint8_t size)
{
    /* Non-compliant: Array size is determined at runtime via variable */
    uint32_t buffer[size]; 

    for (uint8_t i = 0U; i < size; i++)
    {
        buffer[i] = (uint32_t)i;
    }
}

/* Compliant example */
void test_rule_18_8_good(uint8_t size)
{
    /* Compliant: Fixed size allocation using compile-time constant */
    uint32_t buffer[MAX_SIZE];

    if (size <= MAX_SIZE)
    {
        for (uint8_t i = 0U; i < size; i++)
        {
            buffer[i] = (uint32_t)i;
        }
    }
}