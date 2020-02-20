int mx_strlen(const char *s);

int mx_insertion_sort(char **arr, int size) {
    int shifters = 0;

    for (int i = 1; i < size; i++) {
        if (mx_strlen(arr[i]) < mx_strlen(arr[i - 1])) {
            int index = i;
            char *current = arr[i];
            for (; index > 0 && mx_strlen(current) < mx_strlen(arr[index - 1]); index--) {
                arr[index] = arr[index - 1];
                shifters++;
            }
            arr[index] = current;
        }

    }
    return shifters;
}
