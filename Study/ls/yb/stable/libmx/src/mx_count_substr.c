#include "libmx.h"

static void last_change(int *counter, int *i, int *k, int *flag) {
    *counter += 1;
    *i += *k - 1;
    *flag = 0;
}

int mx_count_substr(const char *str, const char *sub) {
    int counter = 0;
    int k = 0;
    int flag = 0;

    if (sub == NULL || str == NULL)
        return -1;
    for (int i = 0; str[i] != '\0'; i++, k = 0)
        if (str[i] == *sub) {
            for (int j = i; sub[k] != '\0'; j++, k++) {
                if (str[j] != sub[k])
                    break;
                else
                    flag++;
            }
            if (flag == mx_strlen(sub)) {
                last_change(&counter, &i, &k, &flag);
            }
        }
    return counter;
}
