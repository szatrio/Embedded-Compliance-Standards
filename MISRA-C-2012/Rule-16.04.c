#include <stdint.h>

/**
 * Compliance Check: MISRA C:2012 Rule 16.4
 * Rule: Every switch statement shall have a default label to handle 
 * unexpected or out-of-range values.
 */
void test_compliance_16_4(uint8_t error_code) {
    
    uint8_t system_action = 0U;

    /* --- NON-COMPLIANT --- */
    /* If 'error_code' is not 0x01 or 0x02, the switch block does nothing.
       This lacks defensive programming against corrupted memory values. */
    /* switch (error_code) {
        case 0x01U:
            system_action = 10U;
            break;
        case 0x02U:
            system_action = 20U;
            break;
    } */


    /* --- MISRA COMPLIANT --- */
    /* A default label is mandatory, even if it only contains a break statement 
       or an error logging function. */
    switch (error_code) {
        case 0x01U:
            system_action = 10U;
            break;
            
        case 0x02U:
            system_action = 20U;
            break;
            
        default:
            /* Mandatory default label to trap any unhandled execution paths */
            system_action = 0xFFU;
            break;
    }
}
