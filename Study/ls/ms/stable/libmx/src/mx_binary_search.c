#include "libmx.h"

int mx_binary_search(char **arr, int size, const char *s, int *count) {
    int first = 0;
    int last = size - 1;

    while (first <= last) {
        int mid = (first + last) / 2;

        (*count)++;
        if (mx_strcmp(s, arr[mid]) == 0) {
            return mid;
        } else if (mx_strcmp(s, arr[mid]) < 0) {
            last = mid - 1;
        } else {
            first = mid + 1;
        }
    }
    *count = 0;
    return -1;
}
