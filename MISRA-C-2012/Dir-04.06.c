#include <stdint.h>

/**
 * Compliance Check: MISRA C:2012 Rule 4.6
 * Rule: Typedefs that indicate size and signedness shall be used 
 *       in place of the basic numerical types.
 */
void test_compliance_4_6(int32_t unused_parameter) {

    /* Use int32_t instead of long to guarantee 32-bit width */
    int32_t sensor_value = 1000; 
    
    /* Use uint8_t instead of char for numeric/status data */
    uint8_t status = 'A';

    if (sensor_value > 0) {
        sensor_value--;
    }
}