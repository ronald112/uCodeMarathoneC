#include <time.h>

double mx_timer(void (*f)()) {
    clock_t start = clock();
    f();
    clock_t stop = clock();
    return (stop - start) / CLOCKS_PER_SEC;
}
