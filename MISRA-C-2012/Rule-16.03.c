#include <stdint.h>

/**
 * Compliance Check: MISRA C:2012 Rule 16.3
 * Rule: An unconditional break statement shall terminate every switch-clause.
 */

/* --- NON-COMPLIANT --- */
void process_mode_bad(uint8_t mode)
{ ancient_status = 0U;
    uint8_t status = 0U;

    switch (mode)
    {
        case 1U:
            status = 10U;
            /* Violation: Missing break statement causes fall-through to case 2U */

        case 2U:
            status = 20U;
            if (mode == 2U)
            {
                break; /* Violation: Break is conditional (inside if statement) */
            }
            break;

        default:
            status = 0U;
            /* Violation: Default clause must also end with break */
    }
}

/* --- MISRA COMPLIANT --- */
void process_mode_good(uint8_t mode)
{
    uint8_t status = 0U;

    switch (mode)
    {
        /* Compliant: Empty case label sharing the same block is allowed */
        case 1U:
        case 2U:
            status = 10U;
            break; /* Compliant: Unconditional break terminates the clause */

        case 3U:
            status = 30U;
            break; /* Compliant: Unconditional break */

        default:
            status = 0U;
            break; /* Compliant: Terminated explicitly with break */
    }
}