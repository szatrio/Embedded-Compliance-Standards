#include <stdint.h>

/**
 * Compliance Check: MISRA C:2012 Rule 20.10
 * Rule: The # and ## preprocessor operators should not be used.
 */

/* --- NON-COMPLIANT EXAMPLES --- */

/* Non-compliant: Use of '#' operator for stringification */
#define STRINGIFY(x) #x

/* Non-compliant: Use of '##' operator for token pasting */
#define CONCAT_VAR(prefix, num) prefix ## num

void demo_bad(void)
{
    /* Generates: uint32_t sensor_1 = 100U; */
    uint32_t CONCAT_VAR(sensor_, 1) = 100U;

    /* Generates string "sensor_1" */
    const char *str = STRINGIFY(sensor_1);

    (void)sensor_1;
    (void)str;
}


/* --- MISRA COMPLIANT EXAMPLES --- */

/* Compliant: Declare explicit identifiers without token-pasting tricks */
static uint32_t g_sensor_1 = 100U;
static uint32_t g_sensor_2 = 200U;

/* Compliant: Use explicit C strings instead of stringification (#) */
static const char g_sensor_1_name[] = "sensor_1";

void demo_good(void)
{
    g_sensor_1 = 105U;
    g_sensor_2 = 205U;

    (void)g_sensor_1_name;
}