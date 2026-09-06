#include <stdint.h>

/**
 * Compliance Check: MISRA C:2012 Rule 21.5
 * Rule: The standard header file <signal.h> shall not be used.
 */

/* --- NON-COMPLIANT EXAMPLE --- */

/* Non-compliant: Including and using <signal.h> facilities is strictly forbidden */
/* #include <signal.h> */

/*
void handle_signal(int sig)
{
    // Asynchronous signal handler execution - Non-compliant
}

void test_rule_21_5_bad(void)
{
    signal(SIGINT, handle_signal); // Non-compliant
    raise(SIGINT);                // Non-compliant
}
*/


/* --- MISRA COMPLIANT EXAMPLE --- */

/* Compliant: Use deterministic polling or explicit status flags instead of signals */
typedef enum
{
    EVENT_NONE = 0,
    EVENT_INTERRUPT_REQUESTED
} event_status_t;

static event_status_t g_event_flag = EVENT_NONE;

void trigger_interrupt_event(void)
{
    /* Set an explicit application-level flag deterministically */
    g_event_flag = EVENT_INTERRUPT_REQUESTED;
}

void test_rule_21_5_good(void)
{
    /* Compliant: Poll for status synchronously in main execution loop */
    if (g_event_flag == EVENT_INTERRUPT_REQUESTED)
    {
        /* Safe, deterministic event handling */
        g_event_flag = EVENT_NONE;
    }
}