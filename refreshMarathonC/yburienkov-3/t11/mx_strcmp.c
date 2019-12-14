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

int mx_strcmp(const char *s1, const char *s2) {  
    // int first_cout = 0;
    // for  (; s1[first_cout]; first_cout++);
    // int sec_count = 0;
    // for (; s2[sec_count]; sec_count++);
    // if (first_cout < sec_count)
    //     return (-s2[sec_count - 1]);
    // else if (first_cout > sec_count)
    //     return (s1[first_cout - 1]);
    // else
    //     for (; *s1; s1++, s2++) {            
    //         if (*s1 != *s2) {
    //             return (*s1 - *s2);
    //         }    
            
    //     }
    // return 0;
    
    int i = 0;
    for (; s1[i] == s2[i]; i++) {
        if (s1[i] == '\0') {
            return 0;
        }
    }
    return s1[i] - s2[i];
}
