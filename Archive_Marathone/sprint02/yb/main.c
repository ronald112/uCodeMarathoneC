#include <stdio.h>
#include <stdbool.h>
#include "t00/mx_is_positive.c"
#include "t01/mx_is_odd.c"
#include "t02/mx_isalpha.c"
#include "t03/mx_isdigit.c"
#include "t04/mx_isspace.c"
#include "t05/mx_islower.c"
#include "t06/mx_isupper.c"
#include "t07/mx_tolower.c"
#include "t08/mx_toupper.c"
#include "t09/mx_isos_triangle.c"
#include "t10/mx_multiple_number.c"
#include "t11/mx_max.c"
#include "t12/mx_mid.c"
#include "t13/mx_sum_digits.c"



int main() {
printf("\n t00 mx_is_positive\n");
mx_is_positive(1235135); //positive
write (1, "\n", 1);

printf("\n t01 mx_is_odd1\n");
printf("%d", mx_is_odd(1)); //1

printf("\n t02 mx_isalpha'a'\n");
printf("%d", mx_isalpha('a')); //1

printf("\n t03 mx_isdigit'A'\n");
printf("%d", mx_isdigit('0')); //0

printf("\n t04 mx_isspace' '\n");
printf("%d", mx_isspace(' ')); //1

printf("\n t05 mx_islower'Z'\n");
printf("%d", mx_islower('Z')); //0

printf("\n t06 mx_isupper'Z'\n");
printf("%d", mx_isupper('Z')); //1

printf("\n t07 mx_tolower 'Z'\n");
printf("%d", mx_tolower('Z')); //z

printf("\n t08 mx_toupper 'z'\n");
printf("%d", mx_toupper('z')); //Z

printf("\n t09 mx_isos_triangle '3, *'\n");


  int length = 3;
  char c = '*';
  mx_isos_triangle(length, c);

printf("\n t10 mx_multiple_number '3, 9'\n");
printf("%d", mx_multiple_number(3, 9)); //1

printf("\n t11 mx_max '-1, 0, 1'\n");
printf("%d", mx_max(-1, 0, 1)); //1

printf("\n t12 mx_mid '5, 16, 10'\n");
printf("%d", mx_mid(10, 20, -10)); //10

printf("\n t13 mx_sum_digits '435. 12'\n");
printf("%d", mx_sum_digits(435)); //12




return 0;
}
