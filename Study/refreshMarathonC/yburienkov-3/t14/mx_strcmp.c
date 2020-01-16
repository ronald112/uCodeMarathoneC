int mx_strcmp(const char *s1, const char *s2) {
	int i = 0;

	for (; s1[i] == s2[i]; i++) {
		if ( s1[i] == '\0') {
			return 0;
		}
	}
	return s1[i] - s2[i];
}

// int mx_strcmp(const char *s1, const char *s2) {    
//     while (*s1) {
//         if (*s1 != *s2) {
//             if (*s1 > *s2) {
//                 return 1;
//                 break;
//             } else if (*s1 < *s2) {
//                 return -1;
//                 break;
//             }
//         }    
//         s1++;
//         s2++;
//     }
//     return 0;
// }
