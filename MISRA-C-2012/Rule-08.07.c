#include <stdint.h>

/* 
 * Rule 8.7: Functions and objects should not be defined with external linkage if
 * they are referenced in only one translation unit.
 */

/* Internal variable used only in this file */
static int32_t internal_counter = 0;

/* Internal function: Only visible within this .c file */
static void update_internal_logic(void) {
    internal_counter++;
}

void test_compliance_8_7(void) {
    /* Compliance 4.6 is already applied here */
    int32_t current_status = 1;

    if (current_status > 0) {
        update_internal_logic();
    }
}