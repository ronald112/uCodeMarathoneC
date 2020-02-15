#include <stdbool.h>

int mx_strlen(const char *s);//
void mx_printint(int n);
void mx_printchar(char c);//
bool mx_isspace(char c);//
bool mx_isdigit(int c);//
int mx_atoi(const char *str);

int main(int argc, char *argv[]) {
    argc += argc;
    // проверка на коректный ввод
    if (mx_atoi(&*argv[1]) < 0 || (mx_atoi(&*argv[1]) % 2 != 0
    && mx_atoi(&*argv[1]) > 1))
        return 0;
    if (mx_atoi(&*argv[2]) < 0 || (mx_atoi(&*argv[2]) % 2 != 0
    && mx_atoi(&*argv[2]) > 1))
        return 0;    
    
    // нахожу размер таблицы    
    int res_of_table = mx_atoi(&*argv[1]) - mx_atoi(&*argv[2]);
    if (res_of_table < 0) 
        res_of_table *= -1; 

    // рисую
    if (mx_atoi(&*argv[1]) != mx_atoi(&*argv[2])) {
        for (int i = 1; i <= res_of_table + 1; i++) {
            for (int j = 1; j <= res_of_table + 1; j++) {
                mx_printint((i * j));
                mx_printchar('\t');
            }            
            mx_printchar('\n');
        }
    }
    else {
        mx_printint((mx_atoi(&*argv[1]) * mx_atoi(&*argv[2])));
        mx_printchar('\n');
    }
    return 0;
}
