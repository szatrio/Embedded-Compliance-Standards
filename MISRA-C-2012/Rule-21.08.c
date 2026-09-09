#include <stdint.h>
#include <stdlib.h>

/**
 * Compliance Check: MISRA C:2012 Rule 21.8
 * Rule: The library functions abort, exit, getenv and system of <stdlib.h>
 *       shall not be used.
 */

/* --- NON-COMPLIANT EXAMPLE --- */

void handle_critical_error_bad(void)
{
    /* Non-compliant: Termination functions like abort/exit are strictly forbidden */
    /* abort(); */
    /* exit(1); */

    /* Non-compliant: OS interaction functions are forbidden */
    /* (void)system("clear"); */
    /* char *env = getenv("PATH"); */
}


/* --- MISRA COMPLIANT EXAMPLE --- */

typedef enum
{
    SYS_STATE_NORMAL = 0,
    SYS_STATE_SAFE_SHUTDOWN,
    SYS_STATE_ERROR
} sys_state_t;

static sys_state_t g_system_state = SYS_STATE_NORMAL;

static void set_hardware_to_safe_state(void)
{
    /* Place all critical peripherals and actuators into safe mode */
}

void handle_critical_error_good(void)
{
    /* Compliant: Transition system into a safe state deterministically */
    set_hardware_to_safe_state();
    g_system_state = SYS_STATE_SAFE_SHUTDOWN;
}

void test_rule_21_8_demo(void)
{
    if (g_system_state == SYS_STATE_ERROR)
    {
        handle_critical_error_good();
    }
}