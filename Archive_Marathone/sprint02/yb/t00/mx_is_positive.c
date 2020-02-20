//mx_is_positive.c

#include "mx_printstr.c"

void mx_is_positive(int i) {
    if (i < 0) {
	mx_printstr("negative\n");
    }
    if (i > 0) {
	mx_printstr("positive\n");
    }
    if (i == 0) {
	mx_printstr("zero\n");
    }
}
