#include <stdint.h>

/**
 * Compliance Check: MISRA C:2012 Rule 1.2
 * Rule: Language extensions should not be used.
 */

/* --- NON-COMPLIANT EXAMPLE --- */

/* Non-compliant: Using non-standard compiler inline assembly extension */
void delay_bad(void)
{
    /* Non-compliant: 'asm' keyword is a compiler language extension */
    /* asm("NOP"); */
}

/* Non-compliant: Non-standard struct attributes or packing extensions */
/* struct __attribute__((packed)) BadHeader { uint8_t id; }; */


/* --- MISRA COMPLIANT EXAMPLES --- */

/* Compliant: Pure standard C functions without relying on non-standard extensions */
void delay_good(void)
{
    volatile uint32_t count;
    for (count = 0U; count < 1000U; count++)
    {
        /* Standard C loop for delay simulation */
    }
}

/* Compliant: Standard C byte manipulation without packed struct extensions */
typedef struct
{
    uint8_t id;
    uint8_t status;
} header_t;

void process_header(void)
{
    header_t pkt = {1U, 0U};
    (void)pkt;
}