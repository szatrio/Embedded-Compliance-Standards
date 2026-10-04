#include <stdint.h>
#include <stdbool.h>

/**
 * Compliance Check: MISRA C:2012 Directive 3.1
 * Directive: All code shall be traceable to documented requirements.
 */

/* --- NON-COMPLIANT EXAMPLE --- */

/* Non-compliant: Code exists without any reference to a documented requirement (Untraceable code) */
void undocumented_debug_backdoor(void)
{
    /* Non-compliant: Secret feature or orphan code not specified in SRS */
    volatile uint32_t secret_flag = 0xDEADBEEFU;
    (void)secret_flag;
}

uint32_t calculate_speed_bad(uint32_t distance, uint32_t time)
{
    /* Non-compliant: Magic constant and untraceable logic without requirement mapping */
    if (time == 0U)
    {
        return 9999U; /* Untraceable fallback behavior */
    }
    return distance / time;
}


/* --- MISRA COMPLIANT EXAMPLES --- */

/**
 * @brief  Calculates speed based on distance and time.
 * @req    REQ-SW-MOT-010: Speed calculation formula shall be (distance / time).
 * @req    REQ-SW-MOT-011: If time is zero, return 0 to prevent division by zero.
 */
uint32_t calculate_speed_good(uint32_t distance, uint32_t time)
{
    uint32_t speed = 0U;

    /* Compliant: Logic explicitly maps to REQ-SW-MOT-011 */
    if (time > 0U)
    {
        /* Compliant: Logic explicitly maps to REQ-SW-MOT-010 */
        speed = distance / time;
    }

    return speed;
}