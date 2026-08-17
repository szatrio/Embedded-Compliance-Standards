#include <stdint.h>

/**
 * Compliance Check: MISRA C:2012 Rule 16.5
 * Rule: A default label shall appear as either the first or the last switch label 
 * of a switch statement.
 */

/* --- NON-COMPLIANT --- */
void process_status_bad(uint8_t status)
{
    uint8_t result = 0U;

    switch (status)
    {
        case 1U:
            result = 10U;
            break;

        /* Violation: 'default' label placed in the middle of case labels */
        default:
            result = 0U;
            break;

        case 2U:
            result = 20U;
            break;
    }
}

/* --- MISRA COMPLIANT --- */
void process_status_good(uint8_t status)
{
    uint8_t result = 0U;

    switch (status)
    {
        case 1U:
            result = 10U;
            break;

        case 2U:
            result = 20U;
            break;

        /* Compliant: 'default' label is placed at the very end of the switch statement */
        default:
            result = 0U;
            break;
    }
}