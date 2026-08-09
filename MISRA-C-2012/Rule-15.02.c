#include <stdint.h>
#include <stdbool.h>

/**
 * Compliance Check: MISRA C:2012 Rule 15.2
 * Rule: The goto statement shall jump to a label declared later in the same function.
 */

/* Mock functions for hardware/status check */
static bool read_sensor_status(void)
{
    return true;
}

static bool init_hardware(void)
{
    return false; /* Simulate initialization failure */
}

/* --- NON-COMPLIANT EXAMPLE --- */
void test_backward_jump_non_compliant(void)
{
    uint8_t retry_count = 0U;

    /* Label is declared BEFORE the goto statement */
retry_label: 

    if (!read_sensor_status()) 
    {
        retry_count++;
        if (retry_count < 3U)
        {
            /* Violation: Backward jump to a label declared earlier in the function */
            goto retry_label; 
        }
    }
}

/* --- MISRA COMPLIANT EXAMPLE --- */
void test_forward_jump_compliant(void)
{
    bool status = false;

    if (!init_hardware())
    {
        /* Compliant: Forward jump to a label declared LATER in the same function (Cleanup/Error handling) */
        goto error_cleanup; 
    }

    /* Normal execution path */
    status = true;

error_cleanup:
    if (!status)
    {
        /* Perform error handling / resource cleanup here */
    }
}

/* --- MISRA COMPLIANT (Alternative using standard loops) --- */
void test_loop_compliant(void)
{
    uint8_t retry_count = 0U;

    /* Compliant: Use standard loop construct for backward iteration instead of goto */
    while ((retry_count < 3U) && (!read_sensor_status()))
    {
        retry_count++;
    }
}