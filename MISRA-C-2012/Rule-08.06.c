#include <stdint.h>

/**
 * Compliance Check: MISRA C:2012 Rule 8.6
 * Rule: An identifier with external linkage shall have exactly one external definition.
 */

/* --- NON-COMPLIANT --- */
/* Violation: Variable or function defined multiple times or defined in a header */

uint32_t g_ticks = 0U; /* Definition 1 */
uint32_t g_ticks = 1U; /* Violation: Redundant definition */

void set_speed(uint16_t rpm) { /* Definition 1 */
    /* Logic */
}
void set_speed(uint16_t rpm) { /* Violation: Redundant definition */
    /* Logic */
}


/* --- MISRA COMPLIANT --- */
/* Compliant: Declaration is external, and the definition exists exactly once */

extern uint32_t g_compliant_ticks;             /* Declaration only */
extern void process_sensor(uint16_t raw);       /* Declaration only */

/* Definition (Implementation - exactly once in the project) */
uint32_t g_compliant_ticks = 0U;

void process_sensor(uint16_t raw) {
    /* Implementation logic here */
}


/* --- COMPLIANT ALTERNATIVE --- */
/* Compliant: Internal linkage using 'static' is exempt from Rule 8.6 */

static uint16_t local_val = 0U;

static void local_delay(void) {
    /* Implementation logic here */
}