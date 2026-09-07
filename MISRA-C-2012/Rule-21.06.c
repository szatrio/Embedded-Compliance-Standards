#include <stdint.h>

/**
 * Compliance Check: MISRA C:2012 Rule 21.6
 * Rule: The Standard Library input/output functions shall not be used.
 */

/* --- NON-COMPLIANT EXAMPLE --- */

/* Non-compliant: Including <stdio.h> and using Standard Library I/O functions */
/*
#include <stdio.h>

void log_status_bad(uint8_t status)
{
    // Non-compliant: printf, sprintf, etc. are forbidden
    printf("Status code: %u\n", status); 
}
*/


/* --- MISRA COMPLIANT EXAMPLE --- */

/* Compliant: Use a custom, deterministic driver function (e.g., UART/Hardware Driver) 
   without relying on <stdio.h> */

static void hw_uart_send_byte(uint8_t byte)
{
    /* Hardware register write logic for I/O operation */
    (void)byte;
}

void log_status_good(uint8_t status)
{
    /* Compliant: Direct, low-level peripheral transmission */
    hw_uart_send_byte(status);
}

void test_rule_21_6_demo(void)
{
    log_status_good(0xAAU);
}