#include <stdint.h>

/**
 * Compliance Check: MISRA C:2012 Rule 8.9
 * Rule: An object should be defined at block scope if its identifier
 *       only appears in a single function.
 */

/* --- NON-COMPLIANT EXAMPLE --- */

/* Non-compliant: 'temp_count' is defined at file scope, 
   but it is only ever used inside process_data_bad() */
static uint32_t temp_count = 0U;

void process_data_bad(void)
{
    temp_count++;
}


/* --- MISRA COMPLIANT EXAMPLES --- */

/* Compliant Example 1: Object moved to block scope with static (retains value between calls) */
void process_data_good(void)
{
    /* Compliant: Defined at block scope because it is only used in this function */
    static uint32_t local_count = 0U;

    local_count++;
}

/* Compliant Example 2: Objects with file scope used across MULTIPLE functions */
static uint32_t shared_status = 0U;

void set_system_status(uint32_t status)
{
    /* Used here... */
    shared_status = status;
}

uint32_t get_system_status(void)
{
    /* ...and used here. File scope is valid because identifier appears in multiple functions */
    return shared_status;
}