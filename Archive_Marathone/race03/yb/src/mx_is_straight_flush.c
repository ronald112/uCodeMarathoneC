#include "minilibmx.h"

bool mx_is_straight_flush(card **hand) {
	if (mx_is_flush(hand) && mx_is_straight(hand)) {
        return true;
	}
    return false;
}
