#include <stdint.h>
#include <stdbool.h>

/**
 * Compliance Check: MISRA C:2012 Directive 4.13
 * Directive: Functions which are designed to provide operations on a resource
 *            should be called in an appropriate sequence.
 */

/* Simulated peripheral driver lifecycle states */
static bool s_is_initialized = false;

static void peripheral_init(void) 
{ 
    s_is_initialized = true; 
}

static void peripheral_write(uint8_t val) 
{ 
    (void)val; 
}

static void peripheral_deinit(void) 
{ 
    s_is_initialized = false; 
}


/* --- NON-COMPLIANT EXAMPLE --- */

/* Non-compliant: Resource operation function called out of sequence (used before initialization) */
void transmit_bad(uint8_t data)
{
    /* Non-compliant: Writing to peripheral without ensuring prior initialization sequence */
    peripheral_write(data);
}


/* --- MISRA COMPLIANT EXAMPLES --- */

/**
 * @brief  Transmits data over the peripheral safely.
 * @note   Compliant with Dir 4.13: Resources are initialized, used, and deinitialized in strict sequence.
 */
void transmit_good(uint8_t data)
{
    /* Compliant: Strict operational sequence is enforced (Init -> Use -> Deinit) */
    peripheral_init();
    
    if (s_is_initialized)
    {
        peripheral_write(data);
        peripheral_deinit();
    }
}