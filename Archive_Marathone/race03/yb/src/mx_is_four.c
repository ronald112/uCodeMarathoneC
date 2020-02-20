#include "minilibmx.h"

bool mx_is_four(card **hand) {
	int counter1 = 1;
	int counter2 = 1;

	for (int i = 1; i < 4; i++) {
		if (hand[i]->rank == hand[i-1]->rank) {
			counter1++;
		}
	}
	for (int j = 4; j > 1; j--) {
		if (hand[j]->rank == hand[j-1]->rank) {
			counter2++;
		}
	}
	if (counter1 == 4 || counter2 == 4) {
		return true;
	}
	return false;
}
