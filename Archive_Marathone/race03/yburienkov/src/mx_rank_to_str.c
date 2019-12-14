#include "minilibmx.h"

void mx_rank_to_str(int rank, char suit, char *container) {
	if (rank == 14) {
		container[0] = 'A';
		container[1] = suit;
		container[2] = '\0';
	} else if (rank == 13) {
		container[0] = 'K';
		container[1] = suit;
		container[2] = '\0';
	} else if (rank == 12) {
		container[0] = 'Q';
		container[1] = suit;
		container[2] = '\0';
	} else if (rank == 11) {
		container[0] = 'J';
		container[1] = suit;
		container[2] = '\0';
	} else if (rank == 10) {
		container[0] = '1';
		container[1] = '0';
		container[2] = suit;
		container[3] = '\0';
	} else {
		container[0] = rank + 48;
		container[1] = suit;
		container[2] = '\0';
	}

}
