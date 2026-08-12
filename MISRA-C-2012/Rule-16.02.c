#include <stdint.h>

/**
 * Compliance Check: MISRA C:2012 Rule 16.2
 * Rule: A switch label shall only be used when the most closely-enclosing 
 * compound statement is the body of a switch statement.
 */

/* --- NON-COMPLIANT --- */
void process_data_bad(uint8_t mode, uint8_t condition)
{
    uint8_t status = 0U;

    switch (mode)
    {
        case 1U:
            status = 10U;
            
            if (condition > 0U)
            {
                /* Violation: 'case 2U' is inside the 'if' block, not directly inside switch */
                case 2U:
                    status = 20U;
                    break;
            }
            break;

        default:
            status = 0U;
            break;
    }
}

/* --- MISRA COMPLIANT --- */
void process_data_good(uint8_t mode, uint8_t condition)
{
    uint8_t status = 0U;

    /* Compliant: All case/default labels are directly enclosed by the switch body */
    switch (mode)
    {
        case 1U:
            status = 10U;
            break;

        case 2U:
            if (condition > 0U)
            {
                status = 20U;
            }
            else
            {
                status = 15U;
            }
            break;

        default:
            status = 0U;
            break;
    }
}