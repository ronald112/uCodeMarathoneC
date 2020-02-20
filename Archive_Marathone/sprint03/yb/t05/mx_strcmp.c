
/*
int mx_strcmp(const char *s1, const char *s2) {
	int i = 0;

	for (int i = 0; s1[i] == s2[i]; i++) {
		if ( s1[i] == '\0') {
			return 0;
		}
	}
	return s1[i] - s2[i];
}
*/


int mx_strcmp(const char *s1, const char *s2) { 
    int count_first = 0;
    int count_sec = 0; 
    while (s1[count_first])
        count_first++;
    while (s2[count_sec])
        count_sec++;
    if (count_first > count_sec)
        return ((unsigned int)s1) - (unsigned int)s2);
    else if (count_first < count_sec)
        return ((unsigned int)s1) - (unsigned int)s2);
    else
    for (int i = 0; i != count_first; i++) {
        if (s1[i] != s2[i]) {
	    return 0;
	    }
    }
    return 0;   
}




/*
int mx_strcmp(const char *s1, const char *s2) {
while (*s1) {

    if (*s1 != *s2)
    break;
    s1++;
    s2++;
}

return ((unsigned int)s1) - (unsigned int)s2);
}
*/
