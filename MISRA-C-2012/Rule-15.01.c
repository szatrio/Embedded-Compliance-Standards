#include <stdint.h>
#include <stdbool.h>

/**
 * Compliance Check: MISRA C:2012 Rule 15.1
 * Rule: The goto statement should not be used.
 */
void test_compliance_15_1(bool hardware_fault_detected) {
    
    uint32_t system_status = 0U;

    /* --- NON-COMPLIANT --- */
    /* Using goto creates unstructured control flow and bypasses 
       standard scope blocks, making code unpredictable. */
    // if (hardware_fault_detected) {
    //     goto ERROR_HANDLER;
    // }

    // system_status = 1U;
    // return;

// ERROR_HANDLER:
    // system_status = 0xFFFFFFFFU;


    /* --- MISRA COMPLIANT --- */
    /* Use standard, structured control flow statements (if/else) 
       to handle errors predictably. */
    if (hardware_fault_detected) {
        system_status = 0xFFFFFFFFU;
    } else {
        system_status = 1U;
    }
}
