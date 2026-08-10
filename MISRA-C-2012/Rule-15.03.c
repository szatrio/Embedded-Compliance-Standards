#include <stdint.h>
#include <stdbool.h>

/**
 * Compliance Check: MISRA C:2012 Rule 15.3
 * Rule: Any label referenced by a goto statement shall be declared in the 
 * same block, or in any block enclosing the goto statement.
 */

void test_rule_15_3_non_compliant(uint8_t status)
{
    if (status == 1U)
    {
        /* NON-COMPLIANT: Jumping into a nested block ('if' statement block) 
           from outside that block violates Rule 15.3 */
        goto inside_block_label; 
    }

    if (status == 2U)
    {
        /* Label is declared inside this nested block */
        inside_block_label: 
        {
            uint8_t data = 100U;
            (void)data;
        }
    }
}

void test_rule_15_3_compliant(uint8_t status)
{
    uint8_t error_code = 0U;

    if (status == 0U)
    {
        error_code = 1U;
        /* COMPLIANT: Jumping to a label declared in an enclosing block 
           (outer function scope) and forward jump compliant with Rule 15.2 */
        goto cleanup; 
    }

    /* Normal execution path */
    error_code = 0U;

/* Label declared in the enclosing/outer block of the function */
cleanup:
    if (error_code != 0U)
    {
        /* Error handling code */
    }
}