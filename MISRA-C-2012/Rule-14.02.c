#include <stdint.h>
#include <stdbool.h>

/**
 * Compliance Check: MISRA C:2012 Rule 14.2
 * Rule: A for loop shall be well-formed.
 */
void test_compliance_14_2(void) {

    uint32_t i = 0U;
    uint32_t limit = 10U;
    uint32_t data[10] = {0U};

    /* --- NON-COMPLIANT --- */

    /* Violation 1: Modifying the loop counter 'i' inside the loop body. */
    for (i = 0U; i < limit; i++) {
        if (data[i] == 0U) {
            i = limit; /* Invalid: Modifying loop counter to force exit */
        }
    }

    /* Violation 2: Modifying the loop limit variable inside the loop body. */
    for (i = 0U; i < limit; i++) {
        if (i == 5U) {
            limit = 5U; /* Invalid: Modifying loop limit inside the body */
        }
    }

    /* Violation 3: Complex loop expression modifying counter in body and clause-3. */
    for (i = 0U; i < 10U; ) {
        /* Logic */
        i++; /* Invalid: Increment should be in the for-clause (clause-3) */
    }


    /* --- MISRA COMPLIANT --- */

    /* Compliant: Loop counter 'i' is initialized in clause-1, tested in clause-2, 
       and modified ONLY in clause-3. Neither 'i' nor 'limit' is modified inside the loop body. */
    for (i = 0U; i < limit; i++) {
        data[i] = i * 2U;
    }

    /* Compliant: If early termination is needed, use a boolean flag in the condition 
       rather than modifying the loop counter inside the body. */
    bool keep_searching = true;

    for (i = 0U; (i < limit) && keep_searching; i++) {
        if (data[i] == 10U) {
            keep_searching = false; /* Compliant: Controlled exit using boolean flag */
        }
    }
}