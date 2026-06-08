#include <stdint.h>
#include <stddef.h>

/**
 * Compliance Check: MISRA C:2012 Rule 18.2
 * Rule: Subtraction between pointers shall only be applied to pointers 
 * that address elements of the same array.
 */

void test_compliance_18_2(void) {
    int32_t sensor_array[10] = {0};
    int32_t other_array[10]  = {0};
    
    int32_t *ptr1 = &sensor_array[5];
    int32_t *ptr2 = &sensor_array[2];
    int32_t *ptr3 = &other_array[3];
    
    ptrdiff_t diff;

    /* --- MISRA COMPLIANT --- */
    /* Allowed: Both pointers belong to 'sensor_array' */
    diff = ptr1 - ptr2; 

    /* --- NON-COMPLIANT --- */
    /* Violation: ptr1 (sensor_array) and ptr3 (other_array) 
       are from different arrays. This is undefined behavior. */
    diff = ptr1 - ptr3; 
}