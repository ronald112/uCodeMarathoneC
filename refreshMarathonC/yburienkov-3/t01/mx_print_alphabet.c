void mx_printchar(char c);

void mx_print_alphabet(void) {
    for (int i = 65, j = 97; j < 123; i++, j++) {        
        if (i % 2 == 0)
            mx_printchar(j);
            else
            mx_printchar(i);            
    }
    mx_printchar('\n');
}
