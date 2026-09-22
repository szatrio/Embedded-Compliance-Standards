#include <stdint.h>

/**
 * Compliance Check: MISRA C:2012 Rule 5.9
 * Rule: Identifiers that define objects or functions with internal linkage
 *       should be unique.
 */

/* ========================================================================== */
/* FILE: file1.c                                                              */
/* ========================================================================== */

/* Internal linkage object in file1.c */
static int32_t sensor_count = 0; 

/* Internal linkage function in file1.c */
static void process_data(void) 
{
    sensor_count++;
}


/* ========================================================================== */
/* FILE: file2.c                                                              */
/* ========================================================================== */

/* --- NON-COMPLIANT EXAMPLE --- */

/* Non-compliant: 'sensor_count' has internal linkage here, but clashes with
   the internal linkage identifier 'sensor_count' in file1.c */
/* static int32_t sensor_count = 0; */ 

/* Non-compliant: Local variable 'process_data' has no linkage, but its name 
   clashes with the internal linkage function 'process_data' in file1.c */
/*
void handle_event_bad(void)
{
    int32_t process_data = 10;
    (void)process_data;
}
*/


/* --- MISRA COMPLIANT EXAMPLE --- */

/* Compliant: Unique identifier name for internal linkage object in file2.c */
static int32_t motor_sensor_count = 0; 

/* Compliant: Unique function and local variable names across all translation units */
static void process_motor_data(void)
{
    motor_sensor_count++;
}

void handle_event_good(void)
{
    int32_t event_status = 10;
    
    process_motor_data();
    (void)event_status;
}