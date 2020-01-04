#include "libmx.h"
// int mx_strcmp(const char *s1, const char *s2) {
// 	int i = 0;

// 	for (; s1[i] == s2[i]; i++) {
// 		if ( s1[i] == '\0') {
// 			return 0;
// 		}
// 	}
// 	return s1[i] - s2[i];
// }

int mx_bubble_sort(char **arr, int size) {
    int swaps = 0;
    int was_swapped = 1;

    for (int i = 0, len1 = size - 1; i < len1 && was_swapped != 0; i++) {
        was_swapped = 0;
        for (int j = 1, len2 = size - i; j < len2; j++) {
            if (mx_strcmp(arr[j-1], arr[j]) > 0) {
                char *temp = arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = temp;
                swaps++;
                was_swapped = 1;
            }
        }
    }
    return swaps;
}
