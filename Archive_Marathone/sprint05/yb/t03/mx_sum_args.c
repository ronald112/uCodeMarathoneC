#include <stdbool.h>

void mx_printchar(char c); 
int mx_atoi(const char *str);
bool mx_isspace(char c);
bool mx_isdigit(int c);
void mx_printint(int n);

int main(int argc, char *argv[]) {
    int sum = 0;
    
    for (int i = 1, n = mx_atoi(&*argv[i]); i < argc; i++) {       
               
        sum += n;        
    }mx_printint(sum);

    return 0;
}
