int mx_strlen(const char *s);
int mx_strcmp(const char *s1, const char *s2);

int mx_selection_sort(char **arr, int size) {
    int counter = 0;
    for (int i = 1; i < size; i++) {
        int min_i = i;
        for (int j = i + 1; j < size; j++) {
            
            if (mx_strcmp(arr[j], arr[min_i]) < 0) {
                min_i = j;
            } 
            else if (mx_strlen(arr[j]) == mx_strlen(arr[min_i])) {
                min_i = j;
            }
        }
        
        if (min_i != i) {
            char *temp = arr[i];
            arr[i] = arr[min_i];
            arr[min_i] = temp;
            min_i = i;
            counter++;
        }
    }   

    return counter;
}
