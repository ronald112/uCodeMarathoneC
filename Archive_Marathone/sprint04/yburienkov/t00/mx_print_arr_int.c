//mx_print_arr_int.c

void mx_printint(int n);
void mx_printchar(char c);

void mx_print_arr_int(const int *arr, int size) {
        for (int i = 0; i < size; i++) {
            if (*arr == 0)
                mx_printchar('0');
            mx_printint(*arr);
            arr++;
            mx_printchar('\n');
        }
}
