#include "libmx.h"

static int calculation(char **arr, int size, int swaps, bool was_swapped) {
    int len1 = size - 1;
    int len2 = 0;

    for (int i = 0; i < len1 && was_swapped != 0; i++) {
        was_swapped = 0;
        len2 = size - i;
        for (int j = 1; j < len2; j++) {
            if (mx_strcmp(arr[j - 1], arr[j]) > 0) {
                char *temp = arr[j - 1];

                arr[j - 1] = arr[j];
                arr[j] = temp;
                swaps++;
                was_swapped = 1;
            }
        }
    }
    return swaps;
}

int mx_bubble_sort(char **arr, int size) {
    int was_swapped = 1;
    int swaps = 0;
    swaps = calculation(arr, size, swaps, was_swapped);

    return swaps;
}
