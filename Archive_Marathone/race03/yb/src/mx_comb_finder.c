#include "minilibmx.h"

void mx_comb_finder(card **hand) {
	if (mx_is_royal_flush(hand)) {
		mx_printstr("Royal flush\n");
		return;
	} else if (mx_is_straight_flush(hand)) {
		mx_printstr("Straight flush\n");
		return;
	} else if (mx_is_four(hand)) {
		mx_printstr("Four of a kind\n");
		return;
	} else if (mx_is_full_house(hand)) {
		mx_printstr("Full house\n");
	} else if (mx_is_flush(hand)) {
		mx_printstr("Flush\n");
		return;
	} else if (mx_is_straight(hand)) {
		mx_printstr("Straight\n");
		return;
	} else if (mx_is_three(hand)) {
		mx_printstr("Three of a kind\n");
		return;
	} else if (mx_is_two_pair(hand)) {
		mx_printstr("Two pair\n");
		return;
	} else if (mx_is_two(hand)) {
		mx_printstr("One pair\n");
		return;
	} else {
		mx_printstr("No pair\n");
		return;
	}
}
