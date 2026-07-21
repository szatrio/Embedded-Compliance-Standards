#include <stdint.h>

/**
 * Compliance Check: MISRA C:2012 Rule 9.2
 * Rule: The initializer for an aggregate or union shall be enclosed in braces.
 */

typedef struct {
    uint16_t x;
    uint16_t y;
} point_t;

typedef struct {
    point_t  pos;
    uint8_t  id;
} entity_t;

/* --- NON-COMPLIANT --- */

void test_non_compliant(void) {
    /* Violation: Missing nested braces for nested aggregate 'pos'. 
       C allows sub-initializer brace elision, but MISRA forbids it. */
    entity_t e1 = { 10U, 20U, 1U }; 

    /* Violation: 2D array initialized without nested braces. */
    uint8_t grid[2][2] = { 1U, 2U, 3U, 4U }; 
}

/* --- MISRA COMPLIANT --- */

void test_compliant(void) {
    /* Compliant: Fully braced initializers matching the structure hierarchy. */
    entity_t e1 = { { 10U, 20U }, 1U }; 

    /* Compliant: Each row of the 2D array is explicitly enclosed in braces. */
    uint8_t grid[2][2] = { { 1U, 2U }, { 3U, 4U } }; 
}