#include <stdint.h>

/**
 * Compliance Check: MISRA C:2012 Rule 5.7
 * Rule: A tag name shall be a unique identifier.
 */

/* --- NON-COMPLIANT --- */
/* Violation: Using the same name for a struct tag and a variable 
   causes unnecessary confusion. */

struct status {
    uint8_t id;
};

void tag_collision_bad(void) {
    /* Confusion: 'status' refers to the struct tag or the variable? */
    uint8_t status = 0U; 
    struct status my_status; 
}

/* --- MISRA COMPLIANT --- */
/* Compliant: Use a distinct naming convention (e.g., '_s' or '_tag' suffix) 
   to clearly distinguish tags from variables. */

struct status_s {
    uint8_t id;
};

void tag_distinct_good(void) {
    uint8_t status = 0U;
    struct status_s my_status;
}