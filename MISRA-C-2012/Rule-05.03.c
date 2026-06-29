#include <stdint.h>

/**
 * Compliance Check: MISRA C:2012 Rule 5.3
 * Rule: An identifier declared in an inner scope shall not hide 
 * an identifier declared in an outer scope.
 */

/* --- NON-COMPLIANT --- */
void shadowing_bad(void) {
    uint16_t status = 0U; /* Variable di outer scope */

    if (/* kondisi */ 1) {
        uint16_t status = 1U; /* Violation: 'status' di sini menutupi 'status' luar */
        
        /* Jika Anda mengubah 'status' di sini, 'status' luar tidak akan terupdate */
    }
}

/* --- MISRA COMPLIANT --- */
void shadowing_good(void) {
    uint16_t outer_status = 0U;

    if (/* kondisi */ 1) {
        uint16_t inner_status = 1U; /* Compliant: Nama berbeda, tidak ada shadowing */
        outer_status = inner_status;
    }
}