//mx_printint.c
#include <stdbool.h>

void mx_printchar(char c); 
int mx_atoi(const char *str);
bool mx_isspace(char c);
bool mx_isdigit(int c);

int main(int argc, char *argv[]) {
    int n = 0;
    for (int i = 1; i < argc; i++) { 
        n = mx_atoi(&*argv[i]);       
        for (int c = 31, k = 0; c >= 0; c--) {
            k = n >> c;

            if (k & 1)
                mx_printchar('1');
            else
                mx_printchar('0');
        }
        mx_printchar('\n');
    }
    return 0;
}
