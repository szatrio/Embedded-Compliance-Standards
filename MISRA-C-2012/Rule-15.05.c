#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

/**
 * Compliance Check: MISRA C:2012 Rule 15.5
 * Rule: A function should have a single point of exit at the end.
 */

/* External helper functions */
extern bool is_hardware_ready(void);
extern uint32_t read_hardware_register(void);

/* --- NON-COMPLIANT EXAMPLE --- */

/* Non-compliant: Multiple exit points / return statements scattered throughout the body */
uint32_t process_sensor_bad(uint32_t *p_out)
{
    if (p_out == NULL)
    {
        return 0U; /* Non-compliant: Early exit point 1 */
    }

    if (!is_hardware_ready())
    {
        return 0U; /* Non-compliant: Early exit point 2 */
    }

    *p_out = read_hardware_register();
    return 1U;     /* Non-compliant: Exit point 3 */
}


/* --- MISRA COMPLIANT EXAMPLE --- */

/* Compliant: Single point of exit at the very end of the function */
uint32_t process_sensor_good(uint32_t *p_out)
{
    uint32_t ret_status = 0U;

    if (p_out != NULL)
    {
        if (is_hardware_ready())
        {
            *p_out = read_hardware_register();
            ret_status = 1U;
        }
    }

    /* Compliant: Single return statement at the end of the function */
    return ret_status;
}