char *mx_strchr(const char *s, int c) {
    while (*s)
    {
        while (*s != c) 
            s++;
        if (*s == c)
            return (char*)s;
        
    }
    return 0;
}
