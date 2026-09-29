#include <stdint.h>
#include <stdbool.h>

/**
 * Compliance Check: MISRA C:2012 Rule 15.4
 * Rule: There should be no more than one break or goto statement
 *       used to terminate any iteration statement.
 */

/* External helper functions */
extern bool check_condition_a(uint32_t val);
extern bool check_condition_b(uint32_t val);

/* --- NON-COMPLIANT EXAMPLE --- */

void process_loop_bad(const uint32_t *arr, uint32_t size)
{
    uint32_t i;

    for (i = 0U; i < size; i++)
    {
        if (check_condition_a(arr[i]))
        {
            break; /* Non-compliant: First break statement */
        }

        if (check_condition_b(arr[i]))
        {
            break; /* Non-compliant: Second break statement in the same loop */
        }
    }
}


/* --- MISRA COMPLIANT EXAMPLES --- */

/* Compliant Example 1: Use a single boolean flag to terminate the loop naturally */
void process_loop_good_flag(const uint32_t *arr, uint32_t size)
{
    uint32_t i = 0U;
    bool should_terminate = false;

    while ((i < size) && (!should_terminate))
    {
        if (check_condition_a(arr[i]) || check_condition_b(arr[i]))
        {
            should_terminate = true; /* Compliant: Terminated cleanly via loop condition */
        }
        else
        {
            i++;
        }
    }
}

/* Compliant Example 2: Combine multiple conditions into a single break statement */
void process_loop_good_single_break(const uint32_t *arr, uint32_t size)
{
    uint32_t i;

    for (i = 0U; i < size; i++)
    {
        /* Compliant: Exactly one break statement used inside the loop */
        if (check_condition_a(arr[i]) || check_condition_b(arr[i]))
        {
            break;
        }
    }
}