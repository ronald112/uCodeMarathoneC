#include "libmx.h"

int mx_sqrt(int x) {
    if (x == 0)
        return 0;
    else {
        int result = x / 2;

        for (;(result >= 0); result--) {
            if ((result * result) == x) {
                return result;
            }
            if (result == 0) 
                return 0;		
        }
        return 0;
    }
}
