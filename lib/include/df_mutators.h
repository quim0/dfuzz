#ifndef DFUZZ_MUTATORS_H
#define DFUZZ_MUTATORS_H

#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#ifdef __MACH__
#include <mach/clock.h>
#include <mach/mach.h>
#endif

#include <df_errors.h>

#define DF_BYTE_MAX 256
#define DF_DEFAULT_DATA_SIZE 4096

// A mutator struct stores the input of the fuzzer, all the mutations done to
// the input will be stored in the mutator, then, they  will return the mutated
// data.
// The len field is the length of the mutated data.
// The cap field is the size of the memory allocation.
typedef struct {
    uint8_t *data;
    size_t len;
    size_t cap;
} mutator_t;

mutator_t df_mutator = { .data=NULL, .len=0, .cap=0 };

// Mutator struct actions
error_t df_mutator_initialize_custom(size_t);
error_t df_mutator_initialize();
error_t df_mutator_destroy();
error_t df_mutator_copyIn(uint8_t*, size_t);

// Mutations
error_t df_mutation_change_byte();

#endif
