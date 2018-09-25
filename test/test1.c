#include <df_mutators.h>
#include <df_errors.h>
#include <stdio.h>

int main() {
    uint8_t *str = (uint8_t*)"1234567890";
    df_print_error(df_mutator_initialize());
    printf("%p: %s\n", df_mutator.data, df_mutator.data);
    df_print_error(df_mutator_copyIn(str, 10));
    printf("%p: %s\n", df_mutator.data, df_mutator.data);
    df_print_error(df_mutation_change_byte());
    printf("%p: %s\n", df_mutator.data, df_mutator.data);
    df_mutator_destroy();
    return 0;
}
