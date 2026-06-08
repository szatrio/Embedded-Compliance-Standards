#include <stdint.h>
#include <stdbool.h>

/**
 * Compliance Check: MISRA C:2012 Rule 17.7
 * Rule: The value returned by a function having non-void return type shall be used.
 */
typedef struct {
    uint32_t status_code;
    bool is_alive;
} GuardSystem_t;

GuardSystem_t update_hardware_watchdog(void) {
    GuardSystem_t system = {0x00000000U, true};
    /* Perform internal register hardware refresh */
    return system;
}

void test_compliance_17_7(void) {
    
    GuardSystem_t current_state = {0xFFFFFFFFU, false};

    /* --- NON-COMPLIANT --- */
    /* Calling a function that returns a value but completely ignoring it. 
       If the function returns a critical error status, the system will miss it. */
    /* update_hardware_watchdog(); */


    /* --- MISRA COMPLIANT --- */
    /* Scenario A: Properly utilizing the return value to update system state */
    current_state = update_hardware_watchdog();

    /* Scenario B: Explicitly casting to (void) to tell the compiler and auditor 
       that ignoring the return value is an intentional, safe decision. */
    (void)update_hardware_watchdog();
}
