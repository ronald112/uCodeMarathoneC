void mx_printchar(char c);


void cube_print_indent(int cube_indent_left) {
    for (int j = 0; j < cube_indent_left; j++) 
                mx_printchar(' ');
}

void cube_print_face(int counter, int cube_width,
int max_cube_height, int cube_indent_left, 
int cube_diag) {
    for (int k = 0; k <= cube_width; k++) {
        if (counter == 0 
        || counter == max_cube_height - 1 
        || counter == cube_diag + 1) {
            if (k == 0 || k == cube_width)
                mx_printchar('+');
            else
                mx_printchar('-');
            }  // печать боковых видимых граней и пробелов
            else  {
                if ((cube_indent_left == 0 && k == 0) 
                || (k == cube_width && cube_indent_left == 0))
                    mx_printchar('|');
                else if ((k == 0 && k < cube_indent_left )
                    || (k == cube_width && counter < cube_diag + 1))
                    mx_printchar('/'); 
                else                    
                    mx_printchar(' ');
            }
    }
}

int cube_print_right_face (int counter, int max_cube_height, 
int cube_indent_right, int cube_diag, int n) {
    if (counter != 0 && counter != max_cube_height - 1) {
                if (counter <= n + 1) {
                    for (int i = 0; i < cube_indent_right; i++) 
                        mx_printchar(' ');                    
                    if (counter == n + 1) 
                    mx_printchar('+');
                    else
                    mx_printchar('|');
                    if (cube_indent_right == cube_diag)
                    ;
                    else
                    cube_indent_right++;                    
                } else {
                //if (counter > n + 1)
                for (int i = 0; i < cube_indent_right - 1; i++) 
                    mx_printchar(' ');                
                cube_indent_right--;
                mx_printchar('/');                
                }      
            }
            return cube_indent_right;
}

void mx_cube(int n) {
    if (n > 1) {
        int cube_height = n, cube_width = n * 2, cube_diag = n / 2;
        int cube_indent_left = cube_diag + 1, cube_indent_right = 0;
        int max_cube_height = cube_height + 2 + cube_diag + 1;
        for (int counter = 0; counter < max_cube_height; counter++) {
            // печать пробелов в начале
            cube_print_indent(cube_indent_left);
            // печать видимых граней
             cube_print_face( counter,  cube_width,   
             max_cube_height,  cube_indent_left, cube_diag);
            // печать правой грани            
            if (counter != 0 && counter != max_cube_height - 1) {
                if (counter <= n + 1) {
                    for (int i = 0; i < cube_indent_right; i++) 
                        mx_printchar(' ');                    
                    if (counter == n + 1) 
                    mx_printchar('+');
                    else
                    mx_printchar('|');
                    if (cube_indent_right == cube_diag)
                    ;
                    else
                    cube_indent_right++;                    
                } else {
                //if (counter > n + 1)
                for (int i = 0; i < cube_indent_right - 1; i++) 
                    mx_printchar(' ');                
                cube_indent_right--;
                mx_printchar('/');                
                }      
            }
            mx_printchar('\n');                
            if (cube_indent_left > 0)
                cube_indent_left--;
        }
    }
}


int main() {
    
    mx_printchar('\n');
    mx_cube(16);
    return 0;
}

