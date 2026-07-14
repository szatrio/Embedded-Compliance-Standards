/* --- File: my_module.h --- */
/* Header file: contains the declaration */
void process_sensor_data(uint16_t sensor_id);


/* --- File: my_module.c --- */
/* Implementation file */
#include "my_module.h" /* <--- COMPLIANT: The declaration is visible here */

void process_sensor_data(uint16_t sensor_id) {
    /* Implementation logic */
}