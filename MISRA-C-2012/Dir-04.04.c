#include <stdint.h>

/**
 * Compliance Check: MISRA C:2012 Directive 4.4
 * Directive: Sections of code should not be "commented out".
 */

/* --- NON-COMPLIANT EXAMPLE --- */

/* Non-compliant: Code logic disabled using comment markers */
void process_sensor_bad(void)
{
    uint32_t sensor_val = 100U;

    /* Non-compliant: Old/disabled code left inside comment block */
    /*
    if (sensor_val > 50U)
    {
        sensor_val = 50U;
    }
    */

    (void)sensor_val;
}


/* --- MISRA COMPLIANT EXAMPLES --- */

/* Compliant: Unused code is completely removed or managed via version control (e.g. Git) */
void process_sensor_good(void)
{
    uint32_t sensor_val = 100U;

    /* Compliant: Only pure explanatory text comments are used */
    /* Apply upper limit threshold to prevent overflow */
    if (sensor_val > 50U)
    {
        sensor_val = 50U;
    }

    (void)sensor_val;
}

/* Compliant: If conditional code removal is genuinely needed, use preprocessor directives */
#if 0
/* Allowed for intentional block exclusion during development/testing */
void legacy_calibration_function(void)
{
    /* Excluded from compilation by preprocessor */
}
#endif