#include "libmx.h"

int mx_atoi(const char *str) {     
   int result = 0;
   //int flag = 0;
  // *char our_str = str;
   while ((mx_isdigit(*str) != 1)) {
        str++;
        }
   while ((mx_isdigit(*str) == 1)) {
      
         result = ((result + (int)*str - 48) * 10);
         //result *= 10;
         //flag = 1;
         str++;
            
      
   }
   result /= 10;
   return result; 
}
