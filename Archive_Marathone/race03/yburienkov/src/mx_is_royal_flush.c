#include "minilibmx.h"

bool mx_is_royal_flush(card **hand) {
	if (mx_is_flush(hand) && hand[0]->rank == 10 
		&& hand[1]->rank == jack && hand[2]->rank == queen 
		&& hand[3]->rank == king && hand[4]->rank == ace) {
        return true;
	}
    return false;
}
