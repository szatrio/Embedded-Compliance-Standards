#include <stdint.h>
#include <stdbool.h>
#include <string.h>

/**
 * Compliance Check: MISRA C:2012 Rule 11.7
 * Rule: A cast shall not be performed between pointer to object and a non-integer arithmetic type.
 */

/* --- NON-COMPLIANT --- */
void non_compliant_demo(void)
{
    uint32_t data = 100U;
    uint32_t *p_data = &data;

    /* Violation: Cast float to pointer */
    uint32_t *ptr1 = (uint32_t *)3.14f;

    /* Violation: Cast pointer to float */
    float f_val = (float)p_data;

    /* Violation: Cast bool to pointer */
    bool flag = true;
    uint32_t *ptr2 = (uint32_t *)flag;

    /* Violation: Cast pointer to bool */
    bool is_valid = (bool)p_data;
}

/* --- MISRA COMPLIANT --- */
void compliant_demo(void)
{
    uint32_t data = 100U;
    uint32_t *p_data = &data;

    /* Compliant: Use comparison instead of casting pointer to bool */
    bool is_not_null = (p_data != NULL);

    /* Compliant: Copy raw float bits via memcpy instead of direct cast */
    float f_sensor = 12.5f;
    uint32_t f_raw_bits;
    (void)memcpy(&f_raw_bits, &f_sensor, sizeof(f_sensor));
}