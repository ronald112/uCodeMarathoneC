// Create a function that prints a ASCII and multibyte characters on standard output.
#include "libmx.h"

void mx_print_unicode(wchar_t c) {
    char out[5] = {0};
    if (c < 0x80) // < 128
        out[0] = (c >> 0 & 0x7f /* 127 */) | 0x00;
    else if (c < 0x0800) { // < 2048 
        out[0] = (c >> 6 & 0x1f) | 0xc0;
        out[1] = (c >> 0 & 0x3f) | 0x80;
    }
    else if (c < 0x010000) { // 65536
        out[0] = (c >> 12 & 0x0f) | 0xe0;
        out[1] = (c >> 6 & 0x3f) | 0x80;
        out[2] = (c >> 0 & 0x3f) | 0x80;
    }
    else { // 1114112 THE VALUE OF THE MAX UNICODE CHARACTER - 1114111
        out[0] = (c >> 18 & 0x07) | 0xf0;
        out[1] = (c >> 12 & 0x3f) | 0x80;
        out[2] = (c >> 6 & 0x3f) | 0x80;
        out[3] = (c >> 0 & 0x3f) | 0x80;
    }
    write(1, out, mx_strlen(out));    
}
