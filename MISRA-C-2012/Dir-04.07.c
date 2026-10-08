#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

/**
 * Compliance Check: MISRA C:2012 Directive 4.7
 * Directive: If a function returns error information, then that error information
 *            shall be tested.
 */

/* Simulated UART transmit function that returns status codes */
typedef enum
{
    UART_OK = 0,
    UART_ERROR_TIMEOUT,
    UART_ERROR_BUSY
} uart_status_t;

static uart_status_t uart_transmit(uint8_t byte)
{
    (void)byte;
    return UART_OK;
}


/* --- NON-COMPLIANT EXAMPLES --- */

/* Non-compliant Example 1: Ignoring return value from file operations */
void read_config_bad(void)
{
    FILE *p_file = fopen("config.bin", "rb");

    /* Non-compliant: 'fread' return value (number of items read) is completely ignored */
    uint8_t buffer[16];
    (void)fread(buffer, sizeof(uint8_t), 16U, p_file);

    if (p_file != NULL)
    {
        (void)fclose(p_file);
    }
}

/* Non-compliant Example 2: Ignoring error status code from driver function */
void send_telemetry_bad(uint8_t data)
{
    /* Non-compliant: 'uart_transmit' returns error status, but caller ignores it */
    uart_transmit(data);
}


/* --- MISRA COMPLIANT EXAMPLES --- */

/* Compliant Example 1: Verifying read count against expected length */
void read_config_good(void)
{
    FILE *p_file = fopen("config.bin", "rb");

    if (p_file != NULL)
    {
        uint8_t buffer[16];
        size_t bytes_read = fread(buffer, sizeof(uint8_t), 16U, p_file);

        /* Compliant: Return value is tested to verify all expected bytes were read */
        if (bytes_read == 16U)
        {
            /* Process valid configuration data */
        }
        else
        {
            /* Handle read error or unexpected EOF */
        }

        (void)fclose(p_file);
    }
}

/* Compliant Example 2: Checking enumerated return status and handling error cases */
void send_telemetry_good(uint8_t data)
{
    /* Compliant: Return status is explicitly captured and tested */
    uart_status_t status = uart_transmit(data);

    if (status != UART_OK)
    {
        /* Handle transmission failure (e.g., retry or log fault) */
    }
}