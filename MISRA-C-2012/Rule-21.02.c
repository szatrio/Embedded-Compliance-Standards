#include <stdint.h>
#include <stddef.h>

/**
 * Compliance Check: MISRA C:2012 Rule 21.2
 * Rule: A reserved identifier or macro name shall not be declared.
 */

/* --- NON-COMPLIANT EXAMPLES --- */

/* Non-compliant: Starts with underscore followed by capital letter (Reserved for implementation) */
extern int32_t _Global_counter;

/* Non-compliant: Re-declaring a standard library function name at file scope */
void printf(const char *format); 

/* Non-compliant: Redefining a standard library typedef name */
typedef uint32_t size_t; 


/* --- MISRA COMPLIANT EXAMPLES --- */

/* Compliant: Standard naming convention without leading underscores or standard library collisions */
extern int32_t global_counter;

/* Compliant: Custom typedef with project specific naming convention */
typedef uint32_t custom_size_t;

/* Compliant: Distinct application function name */
void app_log_message(const char *format)
{
    (void)format;
}

void test_rule_21_2_demo(void)
{
    custom_size_t length = 100U;
    (void)length;
}