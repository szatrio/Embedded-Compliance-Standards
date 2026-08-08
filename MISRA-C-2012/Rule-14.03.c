#include <stdint.h>
#include <stdbool.h>

/**
 * Compliance Check: MISRA C:2012 Rule 14.3
 * Rule: Controlling expressions shall not be invariant.
 */

void test_compliance_14_3(uint8_t sensor_val)
{
    /* --- NON-COMPLIANT --- */

    /* Violation: Expression 'sensor_val >= 0U' is always true for unsigned integer */
    if (sensor_val >= 0U)
    {
        /* Always executed */
    }

    /* Violation: Invariant expression, 10 is always greater than 5 */
    if (10U > 5U)
    {
        /* Always executed */
    }

    /* Violation: Invariant expression evaluating to always false */
    uint8_t flag = 0U;
    if ((flag == 1U) && (flag == 2U))
    {
        /* Dead code: Never executed */
    }


    /* --- MISRA COMPLIANT --- */

    /* Compliant: Controlling expression varies depending on runtime input */
    if (sensor_val > 50U)
    {
        /* Conditional execution based on real dynamic value */
    }

    /* Compliant Exception: Intentional infinite loop for embedded main task */
    while (true)
    {
        /* Main background loop */
        break; /* Added to break for test execution */
    }
}