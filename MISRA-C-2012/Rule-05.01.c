#include <stdint.h>

/**
 * Compliance Check: MISRA C:2012 Rule 5.1
 * Rule: External identifiers shall be distinct.
 */

/* --- NON-COMPLIANT --- */
/* In 'file1.c' */
void motor_control_start(void) { /* ... */ }

/* In 'file2.c' */
/* Violation: Name is too similar or identical to one in 'file1.c', 
   which can cause linking errors or logic bugs. */
void motor_control_stop(void) { /* ... */ } 

/* Another Violation: If the linker only looks at first 6 characters, 
   'sensor_data_input' and 'sensor_data_output' are identical ("sensor"). */
void sensor_data_input(void);
void sensor_data_output(void);

/* --- MISRA COMPLIANT --- */
/* Names are distinct and follow a clear, descriptive convention. Prioritize module name first. */
void motor_start(void);
void motor_stop(void);
void sensor_input_get(void);
void sensor_output_set(void);