#include <stdint.h>
#include <stdarg.h>

/**
 * Compliance Check: MISRA C:2012 Rule 17.1
 * Rule: The features of <stdarg.h> shall not be used.
 */

/* --- NON-COMPLIANT --- */

/* Violation: Using variadic function signature (...) and stdarg.h macros */
uint32_t sum_bad(uint8_t count, ...)
{
    uint32_t total = 0U;
    va_list args;

    /* Violation: Use of va_start */
    va_start(args, count);

    for (uint8_t i = 0U; i < count; i++)
    {
        /* Violation: Use of va_arg (no type checking at compile time) */
        total += (uint32_t)va_arg(args, int);
    }

    /* Violation: Use of va_end */
    va_end(args);

    return total;
}

void test_rule_17_1_bad(void)
{
    /* Violation: Passing mismatched argument types or counts can corrupt stack */
    uint32_t res = sum_bad(3U, 10, 20, 30);
}

/* --- MISRA COMPLIANT --- */

/* Compliant Option 1: Pass data using fixed array and explicit length */
uint32_t sum_good_array(const uint16_t *p_data, uint8_t length)
{
    uint32_t total = 0U;

    if (p_data != NULL)
    {
        for (uint8_t i = 0U; i < length; i++)
        {
            total += (uint32_t)p_data[i];
        }
    }

    return total;
}

/* Compliant Option 2: Use overloaded/distinct functions for fixed parameter sets */
uint32_t sum_two_numbers(uint16_t a, uint16_t b)
{
    return (uint32_t)a + (uint32_t)b;
}

void test_rule_17_1_good(void)
{
    const uint16_t values[3] = {10U, 20U, 30U};
    
    /* Compliant: Type safe and deterministically bounded */
    uint32_t res1 = sum_good_array(values, 3U);
    uint32_t res2 = sum_two_numbers(10U, 20U);
}