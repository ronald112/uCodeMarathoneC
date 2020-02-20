#include "minilibmx.h"

int main(int argc, char const *argv[]) {
	card *hand[5];
	card *duplicate = NULL;

	for (int i = 0; i < 5; i++) {
		hand[i] = (card*)malloc(sizeof(card));
	}

	if (argc != 6) {
		mx_printerr("usage: ./race03 [card1] [card3] [card3] [card4] [card5]\n");
		exit(1);
	}
	
	for (int i = 1, j = 0; i < argc; i++, j++) {
		int error = mx_is_valid_card(argv[i]);

		if (error != 0) {
			mx_printerr("\n");
			exit(error);
		}
	}

	for (int i = 1, j = 0; i < argc; i++, j++) {
		mx_init_card(argv[i], hand[j]);
	}
	mx_sort_cards(hand, 5);

	duplicate = mx_check_dup(hand, 5);
	if (duplicate != NULL) {
		char container[4];
		mx_rank_to_str(duplicate->rank, duplicate->suit, container);
		mx_printerr("Duplicate cards: ");
		mx_printerr(container);
		mx_printerr("\n");
		exit(3);
	}

	mx_comb_finder(hand);	

	for (int i = 0; i < 5; i++) {
		free(hand[i]);
	}
	return 0;
}
