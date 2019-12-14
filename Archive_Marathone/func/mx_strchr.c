int mx_strchr(const char *s1, const char *s2, int n) {    
    int check = 0;
   int i;

   for (i = 0; i < n; i++) {
       if (s1[i] == s2[i]) {
       }
       else check++;
       if(check == 1) break;
   }
   return s1[i] - s2[i];
    
}

/*
int i = 0;
    for (; i < n && s1[i] == s2[i]; ++i)
        ;
        if (i < n) {
            return (s1[i] - s2[i]);
        }

    return (s1[i] - s2[i]); 

 */

