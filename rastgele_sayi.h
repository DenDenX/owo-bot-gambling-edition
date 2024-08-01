#include <stdlib.h>
#include <time.h>

void set_srand() {
    struct timespec ts;
    clock_gettime(CLOCK_REALTIME, &ts);
    srand((ts.tv_sec * 1000LL) + (ts.tv_nsec / 1000000));
}

/* Returns a random number between min and max (inclusive). Does not work with negative numbers.*/
int rrr (int min_deger, int max_deger) {
    return rand() % (max_deger - min_deger + 1) + min_deger;
}

/* Returns the same output as rand() but with a random seed using time(NULL). */
int rr() {
    return rand();
}
