#include <stdint.h>

/**
 * Compliance Check: MISRA C:2012 Rule 2.3
 * Rule: A project should not contain unused type declarations.
 */

/* --- NON-COMPLIANT EXAMPLE --- */

int16_t unused_type_demo_bad(void)
{
    /* Non-compliant: 'local_Type' is declared via typedef but never used anywhere */
    typedef int16_t local_Type;[cite: 1]

    return 67;[cite: 1]
}


/* --- MISRA COMPLIANT EXAMPLES --- */

/* Compliant Example 1: Type is declared and actually used to define a variable */
typedef uint16_t sensor_id_t;

sensor_id_t get_active_sensor_id(void)
{
    /* Compliant: 'sensor_id_t' is used as the return type and variable type */
    sensor_id_t id = 101U;
    return id;
}

/* Compliant Example 2: Remove redundant unused type declarations completely */
int16_t unused_type_demo_good(void)
{
    /* Compliant: Unused typedef removed entirely */
    return 67;
}