char *mx_strncpy(char *dst, const char *src, int len)
{
    int counter = 0;
    while(counter != len)
    {
        dst[counter] = src[counter];
        counter++;
    }
    return dst;
}
