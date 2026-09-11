#include <stdint.h>

/**
 * Compliance Check: MISRA C:2012 Rule 21.10
 * Rule: The Standard Library time and date functions shall not be used.
 */

/* --- NON-COMPLIANT EXAMPLE --- */

/* Non-compliant: Including <time.h> and using time/date standard functions */
/*
#include <time.h>

void test_rule_21_10_bad(void)
{
    time_t raw_time;
    time(&raw_time); // Non-compliant: Standard library time handling
}
*/


/* --- MISRA COMPLIANT EXAMPLE --- */

/* Compliant: Use a deterministic hardware timer / System Tick counter 
   provided by the microcontroller/BSP */

static volatile uint32_t g_system_ticks = 0U;

/* Hardware timer Interrupt Service Routine (ISR) incrementing ticks */
void sys_tick_handler(void)
{
    g_system_ticks++;
}

/* Application logic querying deterministic tick count */
uint32_t get_system_ticks(void)
{
    return g_system_ticks;
}

void test_rule_21_10_good(void)
{
    uint32_t start_tick = get_system_ticks();

    /* Perform application logic */

    uint32_t elapsed_ticks = get_system_ticks() - start_tick;
    (void)elapsed_ticks;
}