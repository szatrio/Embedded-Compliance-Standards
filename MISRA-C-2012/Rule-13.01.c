#include <stdint.h>

/* Global or volatile variables that introduce persistent side effects */
static volatile uint16_t g_sensor_reg = 0x0001U;
static uint16_t g_counter = 0U;

/* Helper function with side effects */
static uint16_t get_next_value(void)
{
    g_counter++; // Persistent side effect: modifies global state
    return g_counter;
}

void process_initialization(void)
{
    /* --- NON-COMPLIANT --- */
    /* Violation: Accessing volatile variable or calling functions with 
     * side effects inside an initializer list leads to unspecified behavior 
     * because evaluation order is not guaranteed.
     */
    // uint16_t bad_array1[2] = { g_sensor_reg, 0U }; /* Violation: volatile read */
    // uint16_t bad_array2[2] = { get_next_value(), 0U }; /* Violation: modifies global state */


    /* --- MISRA COMPLIANT --- */
    /* Compliant: Initialize using pure constants or pre-evaluated variables 
     * without side effects.
     */
    uint16_t safe_val = g_counter; /* Evaluate side effects separately beforehand */
    
    uint16_t good_array[2] = { safe_val, 10U }; /* Compliant: no persistent side effects in list */
    
    (void)good_array;
}