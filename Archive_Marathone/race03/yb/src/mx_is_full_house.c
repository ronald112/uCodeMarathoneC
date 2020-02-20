#include "minilibmx.h"

bool mx_is_full_house(card **hand) {
	int counter1 = 1;
	int counter2 = 1;

	for (int i = 1; i < 3; i++) {
		if (hand[i]->rank == hand[i-1]->rank) {
			counter1++;
		}
	}
	for (int j = 4; j > 2; j--) {
		if (hand[j]->rank == hand[j-1]->rank) {
			counter2++;
		}
	}
	if ((counter1 == 3 && counter2 == 2) || (counter1 == 2 && counter2 == 3)) {
		return true;
	}
	return false;
}
