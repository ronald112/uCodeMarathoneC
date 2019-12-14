#include "minilibmx.h"

bool mx_is_two_pair(card **hand) {
	int counter1 = 1;
	int counter2 = 1;

	for (int i = 1, j = 4; j > i; i++, j--) {
		if (hand[i]->rank == hand[i-1]->rank) {
			counter1++;
		}
		if (hand[j]->rank == hand[j-1]->rank) {
			counter2++;
		}
	}
	if (counter1 == 2 && counter2 == 2) {
		return true;
	}
	return false;
}
