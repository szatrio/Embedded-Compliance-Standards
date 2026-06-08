#include <stdint.h>

/**
 * Compliance Check: MISRA C:2012 Rule 10.3
 * Rule: The value of an expression shall not be assigned to an object with a
 * narrower essential type or of a different essential type category.
 */
void test_compliance_10_3(void) {
    uint16_t raw_adc_sensor_data = 512;
    uint8_t processed_data = 0;

    /* --- NON-COMPLIANT --- */
    /* Implicit truncation! Compiler stays silent, but data is corrupted if values > 255 */
    // processed_data = raw_adc_sensor_data; 


    /* --- MISRA COMPLIANT --- */
    /* Step 1: Validate the data range to ensure it fits the narrower type safely */
    if (raw_adc_sensor_data <= 255U) {
        /* Step 2: Use explicit casting to tell the compiler: 
           "I know what I'm doing, truncate it intentionally." */
        processed_data = (uint8_t)raw_adc_sensor_data;
    } else {
        /* Step 3: Handle out-of-bounds error defensively */
        processed_data = 255U; 
    }
}