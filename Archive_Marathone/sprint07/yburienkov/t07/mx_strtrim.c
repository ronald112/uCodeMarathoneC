#include <stdbool.h>
#include <stdlib.h>

char *mx_strnew(const int size);
char *mx_strncpy(char *dst, const char *src, int len);
int mx_strlen(const char *s);
void mx_strdel(char **str);
bool mx_isspace(char c);

char *mx_strtrim(const char *str) {
    int total_len = mx_strlen(str);
    int first_index = 0;
    int i = 0;
    int j = total_len - 1;
    bool prev_isspace = true;
    bool after_isspace = true;

    if (total_len > 0) {
        prev_isspace = mx_isspace(str[0]);
        after_isspace = mx_isspace(str[total_len-1]);
    } else {
        return NULL;
    }

    while (i < j && (prev_isspace || after_isspace)) {
        if (mx_isspace(str[i]) && prev_isspace == true) {
            total_len--;
            first_index++;
            i++;
        } else {
            prev_isspace = false;
        }
        if (mx_isspace(str[j]) && after_isspace == true) {
            total_len--;
            j--;
        } else {
            after_isspace = false;
        }
    }
    if (i == j && mx_isspace(str[i])) {
        total_len--;
    }
    char *ptr = mx_strnew(total_len);
    ptr = mx_strncpy(ptr, &str[first_index], total_len);
    return ptr;
}

/*
char *result = NULL;
  	

	if (str != NULL) {
		int j = 0;
		for (; mx_isspace(str[j]) ; j++)
		;
		int k = mx_strlen(str) - 1;
		for (; mx_isspace(str[k]) && k > 0; k--)
		;

		int size = j - k;
		if (size < 0)
			size = (size * (-1)) + 1;
		result = mx_strnew(size);

		int lengh = 0;
		for (int i = j; i < size + 1; i++) {		
        	result[lengh++] = str[i];					
		}
	
		result[size + 1] = '\0';

		
    	return result;
	}

	return NULL;	


 */

