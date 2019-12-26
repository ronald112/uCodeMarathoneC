#include "libmx.h"
void mx_str_reverse(char *s) {	
	if (s != NULL)
		for (int i = 0, j = mx_strlen(s) - 1; i < j; j--, i++) 
			mx_swap_char(&s[i], &s[j]);	
}
