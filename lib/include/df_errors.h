#ifndef DFUZZ_ERRORS_H
#define DFUZZ_ERRORS_H

#include <stdint.h>
#include <stdio.h>

typedef enum {
    DF_E_NONE,
    DF_E_VALUE_TOO_SMALL,
    DF_E_ALLOC,
    DF_E_MUTATOR_NOT_INITIALIZED
} error_t;

void df_print_error(error_t err) {
    switch (err) {
        case DF_E_NONE:
            puts("No error");
            break;
        case DF_E_VALUE_TOO_SMALL:
            puts("Value was too small");
            break;
        case DF_E_ALLOC:
            puts("Memory allocation failed");
            break;
        case DF_E_MUTATOR_NOT_INITIALIZED:
            puts("Mutator have not been initialized");
            break;
        default:
            puts("Unknown error type");
    }
}

#endif
