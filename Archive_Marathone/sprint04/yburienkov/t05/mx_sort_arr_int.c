void mx_sort_arr_int(int *arr, int size) {
    int temp = 0;
    for (int i = 0; i < size; i++) {
    temp = arr[0];
        for (int j = 0; j < size; j ++){    
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];            
                arr[j + 1] = temp;           
            }            
        }
    }   
}
