int mx_strcmp(const char *s1, const char *s2);
#include <stdio.h>
int mx_binary_search(char **arr, int size, const char *s, int *count) {
    int first = 0;
    int last = size - 1;

    while (first <= last) {
        int mid = (first + last) / 2;

        if (mx_strcmp(s, arr[mid]) == 0) {
            return mid;
        } else if (mx_strcmp(s, arr[mid]) < 0) {
            last = mid - 1;
            (*count)++;
        } else {
            first = mid + 1;
            (*count)++;
        }
    }
    return -1;
}
