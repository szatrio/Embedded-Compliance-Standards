#include <stdint.h>

/**
 * Compliance Check: MISRA C:2012 Rule 21.4
 * Rule: The standard header file <setjmp.h> shall not be used.
 */

/* --- NON-COMPLIANT EXAMPLE --- */

/* Non-compliant: Including <setjmp.h> is strictly forbidden */
/* #include <setjmp.h> */ 

/*
static jmp_buf env;

void do_task_bad(void)
{
    if (setjmp(env) != 0)
    {
        // Recovery logic after non-local jump
    }
    else
    {
        longjmp(env, 1); // Non-compliant jump
    }
}
*/


/* --- MISRA COMPLIANT EXAMPLE --- */

/* Compliant: Standard C error handling via return values / status codes */
typedef enum
{
    STATUS_OK = 0,
    STATUS_ERROR_INVALID_PARAM,
    STATUS_ERROR_TIMEOUT
} status_t;

static status_t perform_subtask(uint8_t data)
{
    status_t result = STATUS_OK;

    if (data == 0U)
    {
        result = STATUS_ERROR_INVALID_PARAM;
    }
    else
    {
        /* Process data normal flow */
    }

    return result;
}

void test_rule_21_4_good(void)
{
    /* Compliant: Control flow relies on structured function return codes */
    status_t status = perform_subtask(0U);

    if (status != STATUS_OK)
    {
        /* Handle error locally without jumping across functions */
    }
}