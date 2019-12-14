#include <stdio.h>
// int mx_strcmp(const char *s1, const char *s2);

// int mx_strcmp(const char *s1, const char *s2) {    
//     while (*s1) {
//         if (*s1 != *s2) {
//             if (*s1 > *s2) {
//                 return 1;
//                 break;
//             } else if (*s1 < *s2) {
//                 return -1;
//                 break;
//             }
//         }    
//         s1++;
//         s2++;
//     }
//     return 0;
// }

int mx_strcmp(const char *s1, const char *s2) {
	int i = 0;

	for (; s1[i] == s2[i]; i++) {
		if ( s1[i] == '\0') {
			return 0;
		}
	}
	return s1[i] - s2[i];
}

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
