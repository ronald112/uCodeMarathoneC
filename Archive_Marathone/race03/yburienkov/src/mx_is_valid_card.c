#include "minilibmx.h"

int mx_is_valid_card(const char *c) {
	int len = mx_strlen(c);
	int num = mx_atoi(c);
	int digits = 0;
	int chars = 0;
	int flag = 0;

	for (int i = 0; i < len; i++) {
		if (mx_isdigit(c[i]) && flag != 1) {
			digits++;
		} else if (mx_isalpha(c[i])) {
			flag = 1;
			chars++;
		}
	}

	if (digits == 0 && chars == 2) {
		if ((c[0] != 'J' && c[0] != 'Q' && c[0] != 'K' && c[0] != 'A' && c[1] != 'H' && c[1] != 'C' && c[1] != 'S' && c[1] != 'D')) {
			mx_printerr("Invalid card: ");
			mx_printerr(c);
			return 1;
		} else if (c[0] != 'J' && c[0] != 'Q' && c[0] != 'K' && c[0] != 'A') {
			mx_printerr("Invalid card rank: ");
			write(2, c, 1);
			return 3;
		} else if (c[1] != 'H' && c[1] != 'C' && c[1] != 'S' && c[1] != 'D') {
			mx_printerr("Invalid card suit: ");
			write(2, &c[digits+1], chars);
			return 2;
		}
		return 0;
	} 
	if (chars > 1) {
		mx_printerr("Invalid card: ");
		mx_printerr(c);
		return 1;
	}
	if ((num > 10 && chars == 1) && (c[digits] != 'H' && c[digits] != 'C' && c[digits] != 'S' && c[digits] != 'D')) {
		mx_printerr("Invalid card: ");
		mx_printerr(c);
		return 1;
	}
	if (num > 10 || num < 2) {
		mx_printerr("Invalid card rank: ");
		write(2, c, digits);
		return 3;
	} else if (chars > 1 || (c[digits] != 'H' && c[digits] != 'C' && c[digits] != 'S' && c[digits] != 'D')) {
		mx_printerr("Invalid card suit: ");
		write(2, &c[digits], chars);
		return 2;
	}

	return 0;
}
