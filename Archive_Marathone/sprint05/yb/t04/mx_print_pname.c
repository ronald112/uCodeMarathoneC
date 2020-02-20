int mx_strlen(const char *s);
void mx_printstr(const char *s);
void mx_printchar(char c);

int main (int argc, char *argv[]) {
    argc += argc;
    int max_lenth = mx_strlen(argv[0]);
    int count_path = 0;
    for (int i = max_lenth; argv[0][i] != '/'; i--) 
        count_path++; 
    int the_path = max_lenth - count_path;
    mx_printstr(&argv[0][the_path + 1]);
    mx_printchar('\n');
    return 0;
}
