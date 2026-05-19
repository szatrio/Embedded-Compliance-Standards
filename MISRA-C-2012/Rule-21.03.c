#include <stdint.h>
#include <stddef.h>

/* Define a fixed maximum capacity for our system */
#define MAX_SENSOR_LOGS  100U

typedef struct {
    uint32_t timestamp;
    int32_t reading;
} SensorData_t;

/**
 * Compliance Check: MISRA C:2012 Rule 21.3
 * Rule: Dynamic memory allocation (malloc/free) is strictly prohibited.
 * All memory allocation must be static or stack-based.
 */
void test_compliance_21_3(void) {
    
    /* --- NON-COMPLIANT --- */
    /* Requesting memory from Heap at runtime. 
       Risks: Heap fragmentation, NULL pointer returns, and memory leaks if forgotten to free. */
    // SensorData_t *dynamic_log = (SensorData_t *)malloc(sizeof(SensorData_t) * MAX_SENSOR_LOGS);
    
    // if (dynamic_log != NULL) {
    //     dynamic_log[0].reading = 450;
    //     free(dynamic_log); /* Dangerous if pointer is accessed after this line */
    // }


    /* --- MISRA COMPLIANT (Static Allocation) --- */
    /* Allocate a fixed-size buffer globally or locally on the Stack/Data section.
       The memory footprint is determined entirely at compile-time. No surprises at runtime. */
    static SensorData_t static_sensor_logs[MAX_SENSOR_LOGS];

    /* Safe and deterministic access */
    static_sensor_logs[0].timestamp = 1000U;
    static_sensor_logs[0].reading = 450;
}
