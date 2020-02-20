#include "libmx.h"

static int mx_partition(char **arr, int left, int right) {
    char *pivot = arr[(left + (right - 1) / 2)];
    int pindex = left;
    char *temp = NULL;
    
    for (int i = left; i < right - 1; i++) {
        if (mx_strlen(arr[i]) > mx_strlen(pivot)) {
            temp = arr[i];
            arr[i] = arr[pindex];
            arr[pindex] = temp;
            pindex++;
        }
    }
    temp = arr[right - 1];
    arr[right - 1] = arr[pindex];
    arr[pindex]= temp;
    return pindex;
}

int mx_quicksort(char **arr, int left, int right) {
    if (arr == NULL)
        return -1;
    else {
        int counter = 0;

        if (left < right) {
            int pIndex = mx_partition(arr, left, right);

            counter++;
            counter += mx_quicksort(arr, left, pIndex - 1);
            counter += mx_quicksort(arr, pIndex + 1, right);
        }
        return counter;
    }
}
