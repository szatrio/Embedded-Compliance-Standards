#include <stdint.h>

/**
 * Compliance Check: MISRA C:2012 Rule 9.5
 * Rule: Where designated initializers are used to initialize an array object 
 * the size of the array shall be specified explicitly.
 */

/* --- NON-COMPLIANT --- */
void test_rule_9_5_bad(void)
{
    /* Violation: Array size is omitted while using designated initializers.
       The compiler automatically sets the size to 10 based on max index [9]. */
    uint8_t buffer_bad[] = { [0] = 0x01U, [9] = 0xFFU };
}

/* --- MISRA COMPLIANT --- */
void test_rule_9_5_good(void)
{
    /* Compliant: Array size (10) is explicitly specified. */
    uint8_t buffer_good[10] = { [0] = 0x01U, [9] = 0xFFU };

    /* Compliant: Standard positional initialization without designated initializers 
       allows implied size if intention is clear, though specifying explicit size is best. */
    uint8_t table_good[] = { 1U, 2U, 3U, 4U };
}