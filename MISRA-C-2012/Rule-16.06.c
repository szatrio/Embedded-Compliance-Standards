#include <stdint.h>

/**
 * Compliance Check: MISRA C:2012 Rule 16.6
 * Rule: Every switch statement shall have at least two switch-clauses.
 */

/* --- NON-COMPLIANT --- */
void process_state_bad(uint8_t state)
{
    uint8_t result = 0U;

    /* Violation: Switch statement only has ONE switch-clause (case 1U) */
    switch (state)
    {
        case 1U:
            result = 10U;
            break;

        default:
            /* Empty or missing additional functional clauses */
            break;
    }

    /* Violation: Switch statement with NO case labels, only default */
    switch (state)
    {
        default:
            result = 0U;
            break;
    }
}

/* --- MISRA COMPLIANT --- */
void process_state_good(uint8_t state)
{
    uint8_t result = 0U;

    /* Compliant: Switch statement has at least two switch-clauses (case 1U and case 2U/default) */
    switch (state)
    {
        case 1U:
            result = 10U;
            break;

        case 2U:
            result = 20U;
            break;

        default:
            result = 0U;
            break;
    }
}

/* Alternative Compliant Solution for Single Condition */
void process_single_condition_good(uint8_t state)
{
    uint8_t result = 0U;

    /* Compliant: Use 'if' statement when checking only one specific condition */
    if (state == 1U)
    {
        result = 10U;
    }
    else
    {
        result = 0U;
    }
}