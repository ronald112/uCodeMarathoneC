void mx_printchar(char c);
int mx_strlen(const char *s);
void mx_printstr(const char *s);

void race00(int map_length, int map_width, int one_y, int one_x) {
    int sumL = map_length + map_width, sumR = one_y + one_x;
    if ((sumL) > (sumR) && (map_width != 0 || map_length != 0)) {
        for (int i = 0; i < map_length + 2; i++) {
            if (i == 0 || i == map_length + 1) {
                if (map_width == 1)
                    mx_printstr("<==");
                else
                    mx_printstr("<==");
                for (int j = 0; j < map_width - 2; j++)
                    mx_printchar('-');
                if (map_width == 1)
                    mx_printstr(">>");
                else
                    mx_printstr("=>>");                    
                mx_printchar('\n');
            }
            else {                
                if (i % 2 == 0 && i != 0) 
                    mx_printchar('+'); 
                else
                    mx_printchar('*');          
                         
                for (int k = 0; k < map_width; k++) 
                {
                    if (i == one_y + 1 && k == one_x)                  
                        mx_printchar('1');                    
                    else
                        mx_printchar('0');
                }                
                if (i % 2 == 0 && i != 0) 
                    mx_printchar('+'); 
                else
                    mx_printchar('*');                        
                mx_printchar('\n');           
            }
        }
    }
}
