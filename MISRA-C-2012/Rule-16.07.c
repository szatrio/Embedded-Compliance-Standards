#include <stdint.h>
#include <stdbool.h>

/**
 * Compliance Check: MISRA C:2012 Rule 16.7
 * Rule: A switch-expression shall not have essentially Boolean type.
 */

/* --- NON-COMPLIANT --- */
void process_flag_bad(bool is_active, uint8_t val1, uint8_t val2)
{
    uint8_t status = 0U;

    /* Violation: 'is_active' has essentially Boolean type */
    switch (is_active)
    {
        case true:
            status = 10U;
            break;

        case false:
            status = 0U;
            break;

        default:
            status = 0U;
            break;
    }

    /* Violation: Controlling expression (val1 > val2) evaluates to essentially Boolean */
    switch (val1 > val2)
    {
        case true:
            status = 1U;
            break;

        default:
            status = 0U;
            break;
    }
}

/* --- MISRA COMPLIANT --- */
void process_flag_good(bool is_active, uint8_t val1, uint8_t val2)
{
    uint8_t status = 0U;

    /* Compliant: Use if-else statement for Boolean expression */
    if (is_active)
    {
        status = 10U;
    }
    else
    {
        status = 0U;
    }

    /* Compliant: Use if-else for logical relational expressions */
    if (val1 > val2)
    {
        status = 1U;
    }
    else
    {
        status = 0U;
    }
}