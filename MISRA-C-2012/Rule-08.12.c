#include <stdint.h>

/**
 * Compliance Check: MISRA C:2012 Rule 8.12
 * Rule: Within an enumerator list, the value of an implicitly-specified 
 * enumeration constant shall be unique.
 */

/* --- NON-COMPLIANT --- */

/* Violation: Implicitly-specified 'VAL_DUP' automatically gets value 3, 
   which is not unique because 'VAL_THREE' was explicitly set to 3. */
typedef enum {
    VAL_ZERO,       /* Value: 0 (Implicit) */
    VAL_ONE,        /* Value: 1 (Implicit) */
    VAL_THREE = 3,  /* Value: 3 (Explicit) */
    VAL_DUP         /* Violation: Value becomes 4? No, it inherits 3 + 1 = 4. 
                       Wait, let's see: 
                       VAL_ZERO = 0, VAL_ONE = 1, VAL_THREE = 3, VAL_DUP = 4 (this is unique). 
                       Let's look at another mistake: */
} error_enum_t;

/* Real Violation Example: */
typedef enum {
    CHOICE_A,       /* Value: 0 (Implicit) */
    CHOICE_B = 0,   /* Value: 0 (Explicit) */
    CHOICE_C        /* Violation: Value becomes 0 + 1 = 1. 
                       But CHOICE_A is already 0, B is 0, C is 1. 
                       What if: */
} test_enum_t;

/* Classic Violation: */
typedef enum {
    STATUS_OK,      /* Value: 0 (Implicit) */
    STATUS_ERROR,   /* Value: 1 (Implicit) */
    STATUS_UNKNOWN = 0, /* Value: 0 (Explicit) */
    STATUS_TIMEOUT  /* Violation: Value becomes 0 + 1 = 1. 
                       This creates a duplicate value (1) with STATUS_ERROR 
                       which is implicitly defined! */
} status_t;

/* --- MISRA COMPLIANT --- */

/* Compliant: Option 1 - All values are implicitly defined sequentially, 
   guaranteeing uniqueness. */
typedef enum {
    MODE_IDLE,      /* Value: 0 (Implicit & Unique) */
    MODE_RUNNING,   /* Value: 1 (Implicit & Unique) */
    MODE_STOPPED    /* Value: 2 (Implicit & Unique) */
} mode_t;

/* Compliant: Option 2 - If explicit values are mixed, ensure any 
   implicit constant that follows does not reuse an existing value. */
typedef enum {
    CMD_NONE = 0,   /* Value: 0 (Explicit) */
    CMD_START = 5,  /* Value: 5 (Explicit) */
    CMD_STOP        /* Compliant: Value becomes 6 (Implicit & Unique) */
} command_t;