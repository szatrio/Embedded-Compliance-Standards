#include <stdint.h>

/**
 * Compliance Check: MISRA C:2012 Rule 16.1
 * Rule: All switch statements shall be well-formed.
 */

/* --- NON-COMPLIANT --- */
void process_state_bad(uint8_t state)
{
    uint8_t result = 0U;

    switch (state)
    {
        result = 1U; /* Violation: Code executed before the first case label */

        case 1U:
            result = 10U;
            /* Violation: Missing break statement (unintended fall-through) */

        case 2U:
            result = 20U;
            break;

        /* Violation: Missing default clause */
    }
}

/* --- MISRA COMPLIANT --- */
void process_state_good(uint8_t state)
{
    uint8_t result = 0U;

    /* Compliant: Well-formed switch statement structure */
    switch (state)
    {
        case 1U:
            result = 10U;
            break;

        case 2U:
            result = 20U;
            break;

        default:
            /* Compliant: Default clause handles unexpected states */
            result = 0U;
            break;
    }
}