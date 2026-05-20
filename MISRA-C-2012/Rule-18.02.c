#include <stdint.h>
#include <stddef.h>

static int32_t *global_temperature_ptr = NULL;

void read_sensor_stack(void) {
    int32_t local_temp_reading = 35;

    /* --- NON-COMPLIANT --- */
    /* global_temperature_ptr = &local_temp_reading; */
}

void test_compliance_18_2(void) {
    
    read_sensor_stack();
    
    /* --- NON-COMPLIANT --- */
    /* int32_t corrupted_data = *global_temperature_ptr; */


    /* --- MISRA COMPLIANT --- */
    static int32_t static_temp_reading = 35; 
    global_temperature_ptr = &static_temp_reading; 
}
