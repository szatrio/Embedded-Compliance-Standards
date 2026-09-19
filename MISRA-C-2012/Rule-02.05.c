#include <stdint.h>

/**
 * Compliance Check: MISRA C:2012 Rule 2.5
 * Rule: A project should not contain unused macro declarations.
 */

/* Helper function declaration */
extern void use_int16(int16_t val);

/* --- NON-COMPLIANT EXAMPLE --- */

void use_macro_bad(void)
{
#define SIZE 4   /* Compliant: SIZE is used below */
#define DATA 3   /* Non-compliant: DATA is declared but never used */[cite: 1]

    use_int16(SIZE);[cite: 1]
}


/* --- MISRA COMPLIANT EXAMPLES --- */

/* Compliant Example 1: Remove unused macro completely */
void use_macro_good(void)
{
#define BUFFER_SIZE 4   /* Compliant: Macro is defined and used */

    use_int16(BUFFER_SIZE);
}

/* Compliant Example 2: Both macros are used appropriately */
#define ALARM_THRESHOLD 50U
#define ERROR_FLAG      0x01U

uint8_t check_sensor_status(uint8_t current_val)
{
    uint8_t status = 0U;

    /* Compliant: Both macros declared above are expanded in code */
    if (current_val > ALARM_THRESHOLD)
    {
        status = ERROR_FLAG;
    }

    return status;
}