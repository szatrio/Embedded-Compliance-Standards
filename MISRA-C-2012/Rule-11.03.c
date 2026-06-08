#include <stdint.h>

/**
 * Compliance Check: MISRA C:2012 Rule 11.3
 * A cast shall not be performed between a pointer to object type and a
 * pointer to a different object type
 */
void test_compliance_11_3(void) {
    
    /* A byte array representing a raw data buffer (e.g., from UART or SPI) */
    uint8_t raw_buffer[4] = {0x11, 0x22, 0x33, 0x44};
    
    /* Destination pointers */
    uint8_t *allowed_ptr = &raw_buffer[0];
    uint32_t *dangerous_ptr = NULL;

    /* --- NON-COMPLIANT --- */
    /* Casting uint8_t* to uint32_t*. 
       This is highly illegal in MISRA because it can trigger an Alignment Fault 
       on many MCUs if the array address is not a multiple of 4. */
    // dangerous_ptr = (uint32_t *)allowed_ptr;
    // uint32_t corrupted_data = *dangerous_ptr; 


    /* --- MISRA COMPLIANT (The Safe Way) --- */
    /* If you need to combine bytes into a larger type, do it explicitly 
       using Bitwise Shifting, NOT pointer casting. This is safe on ALL hardware. */
    uint32_t safe_combined_data = ((uint32_t)raw_buffer[0]) |
                                  ((uint32_t)raw_buffer[1] << 8) |
                                  ((uint32_t)raw_buffer[2] << 16) |
                                  ((uint32_t)raw_buffer[3] << 24);
}
