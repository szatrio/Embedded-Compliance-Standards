#include <stdint.h>

/**
 * Compliance Check: MISRA C:2012 Rule 2.7
 * Rule: There should be no unused parameters in functions.
 */

/* --- NON-COMPLIANT EXAMPLES --- */

/* Non-compliant: Parameter 'unusedpara' is declared but never used in body */
void withunusedpara(uint16_t *para1, int16_t unusedpara)[cite: 1]
{
    if (para1 != NULL)
    {
        *para1 = 42U;[cite: 1]
    }
}

/* Non-compliant: Parameter name omitted in declaration prototype */
/* void process_data(uint16_t); */


/* --- MISRA COMPLIANT EXAMPLES --- */

/* Compliant Example 1: Remove the unused parameter completely */
void withunusedpara_good(uint16_t *para1)
{
    if (para1 != NULL)
    {
        *para1 = 42U;
    }
}

/* Compliant Example 2: All parameters are named in prototype and used in body */
void process_data_good(uint16_t sensor_value, uint16_t *out_result);

void process_data_good(uint16_t sensor_value, uint16_t *out_result)
{
    if (out_result != NULL)
    {
        *out_result = sensor_value * 2U;
    }
}

/* Compliant Example 3: Function without parameters uses void explicitly */
uint32_t get_system_status(void)
{
    return 0U;
}