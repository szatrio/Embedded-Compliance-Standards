#include <stdint.h>
#include <stddef.h>

/**
 * Compliance Check: MISRA C:2012 Rule 18.4
 * Rule: The +, -, += and -= operators should not be applied to an expression of pointer type.
 */
void test_compliance_18_4(void) {
    
    uint8_t data_buffer[5] = {10, 20, 30, 40, 50};
    uint8_t *ptr_one = &data_buffer[0];
    uint8_t *ptr_two = NULL;
    uint8_t value = 0U;

    /* --- NON-COMPLIANT --- */
    /* Performing arbitrary pointer arithmetic outside of clear array indexing. 
       This can easily lead to out-of-bounds memory access. */
    // ptr_two = ptr_one + 3;
    // value = *ptr_two;


    /* --- MISRA COMPLIANT --- */
    /* Array indexing is the only allowed form of pointer arithmetic 
       because bounds checking can be explicitly managed. */
    uint8_t index = 3U;
    if (index < 5U) {
        value = data_buffer[index];
    }
}
