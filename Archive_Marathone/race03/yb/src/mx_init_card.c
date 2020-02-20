#include "minilibmx.h"

void mx_init_card(const char *c, card *c_card) {
	int len = mx_strlen(c);
	int num = mx_atoi(c);

	if (len == 2) {
		if (num != 0) {
			c_card->rank = num;
			c_card->suit = mx_toupper(c[1]);
		} else {
			if (mx_toupper(c[0]) == 'J') c_card->rank = 11;
			if (mx_toupper(c[0]) == 'Q') c_card->rank = 12;
			if (mx_toupper(c[0]) == 'K') c_card->rank = 13;
			if (mx_toupper(c[0]) == 'A') c_card->rank = 14;
			c_card->suit = c[1];
		}

	} else {
		c_card->rank = num;
		c_card->suit = c[2];
	}
}
