#include "minilibmx.h"

void mx_sort_cards(card **arr, int size) {
    int flag = 0;

    for (int i = 0; i < size; i++) {
        card *min = arr[i];
        int index = i;

        for (int j = i + 1; j < size; j++) {
            if (arr[j]->rank < min->rank) {
                min = arr[j];
                index = j;
                flag = 1;
            }
        }
        if (flag == 1) {
            arr[index] = arr[i];
            arr[i] = min;
        }
        flag = 0;
    }
}
