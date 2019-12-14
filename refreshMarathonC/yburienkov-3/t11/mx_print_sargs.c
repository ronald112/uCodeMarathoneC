void mx_printchar(char c); 
int mx_strlen(const char *s);
void mx_printstr(const char *s);
int mx_strcmp(const char *s1, const char *s2);

#include <string.h>

int main (int argc, char *argv[]) {      
    char *buffer;
    for (int i = 0; i < argc; i++) {
        for (int j = 1; j < argc - 1 - i; j++) {
             if ((mx_strcmp(argv[j], argv[j + 1])) > 0) {
                buffer = argv[j];
                argv[j] = argv[j + 1];
                argv[j + 1] = buffer;
            }
        }
    }
    
    for (int i = 1; i < argc; i++) {
        mx_printstr(argv[i]);
        mx_printchar('\n');
    }

    return 0;
}
