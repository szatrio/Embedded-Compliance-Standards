#include <stdint.h>
#include <stdbool.h>

/**
 * Compliance Check: MISRA C:2012 Rule 10.5
 * Rule: The value of an expression should not be cast to an inappropriate essential type.
 */

typedef enum
{
    MODE_OFF = 0,
    MODE_ON  = 1
} mode_t;

/* --- NON-COMPLIANT EXAMPLES --- */

void cast_demo_bad(uint8_t u8_val, int32_t s32_val)
{
    /* Non-compliant: Casting integer expression directly to boolean type */
    bool is_active = (bool)u8_val;

    /* Non-compliant: Casting arbitrary integer directly to enum type */
    mode_t current_mode = (mode_t)s32_val;

    (void)is_active;
    (void)current_mode;
}


/* --- MISRA COMPLIANT EXAMPLES --- */

void cast_demo_good(uint8_t u8_val, int32_t s32_val)
{
    /* Compliant: Use relational expression (==, !=, >, <) to obtain a boolean value */
    bool is_active = (u8_val != 0U);

    /* Compliant: Validate range/value before assigning to enum type */
    mode_t current_mode;
    if (s32_val == 1)
    {
        current_mode = MODE_ON;
    }
    else
    {
        current_mode = MODE_OFF;
    }

    (void)is_active;
    (void)current_mode;
}