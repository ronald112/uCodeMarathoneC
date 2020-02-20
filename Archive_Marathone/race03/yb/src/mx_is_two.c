#include "minilibmx.h"

bool mx_is_two(card **hand) {
	int counter = 1;

	for (int i = 1; i < 5; i++) {
		if (hand[i]->rank == hand[i-1]->rank) {
			counter++;
		}
	}
	if (counter == 2) {
		return true;
	}
	return false;
}
