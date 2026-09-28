#include <stdint.h>

/**
 * Compliance Check: MISRA C:2012 Rule 13.3
 * Rule: A full expression containing an increment (++) or decrement (--)
 *       operator should have no other potential side effects.
 */

/* External function with side effect */
extern uint32_t get_next_value(void);

/* --- NON-COMPLIANT EXAMPLES --- */

void increment_side_effect_bad(uint32_t x, uint32_t y)
{
    uint32_t a;
    uint32_t b;

    /* Non-compliant: Increment operator combined with assignment (another side effect) */
    a = x++;

    /* Non-compliant: Increment operator combined with a function call side effect */
    b = y++ + get_next_value();

    (void)a;
    (void)b;
}


/* --- MISRA COMPLIANT EXAMPLES --- */

void increment_side_effect_good(uint32_t x, uint32_t y)
{
    uint32_t a;
    uint32_t b;
    uint32_t func_val;

    /* Compliant: Assignment separated from increment operator */
    a = x;
    x++;

    /* Compliant: Function call and increment isolated into distinct full expressions */
    func_val = get_next_value();
    b = y + func_val;
    y++;

    (void)a;
    (void)b;
}

void loop_increment_good(void)
{
    uint32_t i;

    /* Compliant: In a standard for-loop header, the increment is an isolated full expression */
    for (i = 0U; i < 10U; i++)
    {
        /* Loop body */
    }
}