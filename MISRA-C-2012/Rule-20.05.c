#include <stdint.h>

/**
 * Compliance Check: MISRA C:2012 Rule 20.5
 * Rule: #undef should not be used.
 */

/* --- NON-COMPLIANT EXAMPLE --- */

#define QUALIFIER volatile

/* Non-compliant: Use of #undef directive */
#undef QUALIFIER /* cite: 1 */


/* --- MISRA COMPLIANT EXAMPLE --- */

/* Compliant: Define macros with unique, scoped names without un-defining them */
#define MODULE_A_QUALIFIER volatile
#define MODULE_B_QUALIFIER const

void process_data_good(void)
{
    MODULE_A_QUALIFIER uint32_t reg_val = 0U;
    MODULE_B_QUALIFIER uint32_t const_val = 100U;

    (void)reg_val;
    (void)const_val;
}