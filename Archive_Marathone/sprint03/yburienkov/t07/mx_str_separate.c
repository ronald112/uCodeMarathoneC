//mx_str_separate.c

void mx_printchar(char c);

void mx_str_separate(const char *str, char delim) {
    
    int i = 0;
    int check = 0;
    while (str[i] != '\0') {
        
        if (str[i] == delim) {
            if (check == 0){
                check++;
                mx_printchar('\n');
            }
        ++i;
        }        
        else {
        mx_printchar(str[i]);            
        i++;
        check = 0;
        }        	    
    }
    mx_printchar('\n');   
    
}
