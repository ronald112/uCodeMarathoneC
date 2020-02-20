#include "header.h"

void mx_math(int *num, char *mass, t_coor *coor, int len, int hight ) {
	int count = 1;
	for (int i = 0; i <= hight; i++) {
        for (int j = 0; j < len; j++) { 
			*(num + len * i + j) = -1;
		}
	}
	
	*(mass + len * coor->x1 + coor->y1) = '@';
	*(num + len * coor->x1 + coor->y1) = 0;
	while (count != 0) {
		count = 0;
		for (int i = 0; i <= hight + 1; i++) {
			for (int j = 0; j < len; j++) {
				if (*(mass + len * i + j) == '@'){
					int buf = *(num + len * i + j);
					if (*(mass + len * (i + 1) + j) == '.') {
						*(mass + len * (i + 1) + j) = '@';
						*(num + len * (i + 1) + j) = buf + 1;
						count++;
					}
                    if (*(mass + len * (i  - 1) + j) == '.' && i != 0) {
						*(mass + len * (i  - 1) + j) = '@';
						*(num + len * (i - 1) + j) = buf + 1;
						count++;
					}
            	    if (*(mass + len * i + j + 1) == '.') {
							*(mass + len * i + j + 1) = '@';
							*(num + len * i + j + 1) = buf + 1;
							count++;
					}
            	    if (*(mass + len * i + j - 1) == '.') {
						*(mass + len * i + j - 1) = '@';
						*(num + len * i + j - 1) = buf + 1;
						count++;
					}
				}
			}
		}
	}
}

