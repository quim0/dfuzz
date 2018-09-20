#include <df_errors.h>
#include <df_mutators.h>
#include <stdio.h>

int main() {
    uint8_t *str = (uint8_t*)"1234567890";
    df_mutator_initialize();
    df_mutator_copyIn(str, 10);
    df_mutation_change_byte();
    puts(df_mutator.data);
    df_mutator_destroy();
    return 0;
}
