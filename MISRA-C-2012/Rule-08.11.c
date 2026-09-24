#include <stdint.h>

/**
 * Compliance Check: MISRA C:2012 Rule 8.11
 * Rule: When an array with external linkage is declared,
 *       its size should be explicitly specified.
 */

#define ARRAY_SIZE 10U

/* ========================================================================== */
/* FILE: module_a.c (Definition)                                              */
/* ========================================================================== */

/* Definition of array with external linkage */
uint32_t g_sensor_data[ARRAY_SIZE] = {0U};


/* ========================================================================== */
/* FILE: module_b.c (External Declaration & Usage)                            */
/* ========================================================================== */

/* --- NON-COMPLIANT EXAMPLE --- */

/* Non-compliant: External array declaration without explicit size */
/* extern uint32_t g_sensor_data[]; */

/*
void process_data_bad(void)
{
    // uint32_t len = sizeof(g_sensor_data); // Compile error / Unsafe!
    g_sensor_data[0] = 100U;
}
*/


/* --- MISRA COMPLIANT EXAMPLE --- */

/* Compliant: Size is explicitly specified in the extern declaration */
extern uint32_t g_sensor_data[ARRAY_SIZE];

void process_data_good(void)
{
    /* Compliant: Safe to evaluate size or access elements */
    g_sensor_data[0] = 100U;
}