int mx_count_words(const char *str, char delimiter) {   
    int checker = 0; 
    unsigned result = 0; 
    while (*str) 
    {         
        if (*str == ' ' && delimiter == ' ') 
            checker = 0;   
        else if (*str == delimiter)
            checker = 0;        
        else if (checker == 0) 
        { 
            checker = 1; 
            ++result; 
        }          
        ++str; 
    }   
    return result; 
} 
    