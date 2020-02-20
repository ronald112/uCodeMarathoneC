#include <stdbool.h>

bool mx_isspace(int c) {
    if ( c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == ' ' || c == '\r' )
        return true;   
    else 
	return false;
}

