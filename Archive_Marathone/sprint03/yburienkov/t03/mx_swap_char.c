void mx_swap_char(char *s1, char *s2) {
    char temp_charac = ' ';
    temp_charac = *s1;
    *s1 = *s2;
    *s2 = temp_charac;
}
