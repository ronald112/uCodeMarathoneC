#include "minilibmx.h"

card *mx_check_dup(card **arr, int size) {

	for (int i = 1; i < size ; i++) {
		if (arr[i-1]->rank == arr[i]->rank && arr[i-1]->suit == arr[i]->suit) {
			return arr[i-1];
		}
	}
	return NULL;
}
