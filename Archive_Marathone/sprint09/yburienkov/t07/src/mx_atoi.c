#include <stdbool.h>

bool mx_isspace(char c);

bool mx_isdigit(int c);

int mx_atoi(const char *str) {
	int sign;
	int output;

	sign = 1;
	output = 0;
	while (mx_isspace(*str) || *str == '+')
		str++;
	if (*str == '-'){
		sign = -1;
		str++;
	}
	while (mx_isdigit(*str)){
		output = output * 10 + *str - '0';
		str++;
	}
    
	return (output * sign);
}

/*
#include <stdbool.h>
bool mx_isspace(char c);
bool mx_isdigit(int c);

int mx_atoi(const char *str) {
    int sign = 1;
    int number = 0;
    int int_len = 0;
    int first = 0;
    double power = 0.1;
    int flag = 1;

    for (int i = 0; str[i] != '\0'; i++) {
        if (mx_isspace(str[i])) {
            first++;
        }
    }
    if (str[first] == '-') {
        sign = -1;
        first++;
    }
    for (int j = first; str[j] != '\0'; j++) {

        if (mx_isdigit(str[j]) && flag == 1) {
            power *= 10;
            int_len++;

        } else {
            flag = 0;
        }
    }
    for (int k = first, len = first + int_len; k < len; k++, power /= 10) {
        number += power*(str[k] - 48);

    }
    return number*sign;
}
 */

