#include "minilibmx.h"

bool mx_is_straight(card **hand) {
	for (int i = 1; i < 5; i++) {
		if (hand[i]->rank - hand[i-1]->rank != 1) {
			if (i == 4 && hand[4]->rank == 14 && hand[0]->rank == 2) {
				return true;
			}
			return false;
		}
	}
    return true;
}
