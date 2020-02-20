//mx_sqrt.c

int mx_sqrt(int x) {    
    int result = 0;    
    int i = 0;    
    while ((i * i) != x) {        
        i++;
        result = i;
    }
    return result;
}
