int mx_strlen(const char *s) {
    int counter = 0;
    for (; *s != '\0'; s++, counter++);
    return counter;
}
