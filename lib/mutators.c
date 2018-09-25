#include <df_mutators.h>
#include <df_errors.h>

#define CHECK_MUTATOR if (!df_mutator.data || !df_mutator.cap) \
                    return DF_E_MUTATOR_NOT_INITIALIZED;

void get_current_utc_time(struct timespec *ts) {
#ifdef __MACH__
    clock_serv_t cclock;
    mach_timespec_t mts;
    host_get_clock_service(mach_host_self(), CALENDAR_CLOCK, &cclock);
    clock_get_time(cclock, &mts);
    mach_port_deallocate(mach_task_self(), cclock);
    ts->tv_sec = mts.tv_sec;
    ts->tv_nsec = mts.tv_nsec;
#else
    clock_gettime(CLOCK_REALTIME, ts);
#endif
}

int get_rand(int to) {
    return rand () % (to + 1);
}

error_t df_mutator_destroy() {
    CHECK_MUTATOR
    free (df_mutator.data);
    df_mutator.data = NULL;
    df_mutator.len = 0;
    df_mutator.cap = 0;
    return DF_E_NONE;
}

error_t df_mutator_initialize_custom(size_t len) {
    if (len < 1) {
        return DF_E_VALUE_TOO_SMALL;
    }
    df_mutator.data = calloc (len, sizeof(uint8_t));
    if (!df_mutator.data) {
        return DF_E_ALLOC;
    }
    printf("data: %p\n", df_mutator.data);
    df_mutator.len = 0;
    df_mutator.cap = len;

    // Use nanoseconds instead of seconds
    struct timespec ts;
    get_current_utc_time(&ts);
    srand((time_t)ts.tv_nsec);
    printf("data: %p\n", df_mutator.data);

    return DF_E_NONE;
}

error_t df_mutator_initialize() {
    return df_mutator_initialize_custom(DF_DEFAULT_DATA_SIZE);
}

error_t df_mutator_copyIn(uint8_t *data, size_t len) {
    CHECK_MUTATOR
    if (len > df_mutator.cap) {
        if (!realloc (df_mutator.data, len)) return DF_E_ALLOC;
    }

    memcpy(df_mutator.data, data, len);
    df_mutator.len = len;
    return DF_E_NONE;
}

error_t df_mutation_change_byte() {
    CHECK_MUTATOR
    int n = get_rand (df_mutator.len - 1);
    int val = get_rand (DF_BYTE_MAX);
    printf("VAL: 0x%x, n: %i\n", val, n);
    df_mutator.data[n] = val;
    return DF_E_NONE;
}
