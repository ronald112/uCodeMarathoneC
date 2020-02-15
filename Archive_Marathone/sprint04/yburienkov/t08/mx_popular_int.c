int mx_popular_int(const int *arr, int size) {    
    int max_count = 1, curr_count = 1, result = 0;  
     
    for (int i = 1; i < size; i++) { 
        if (arr[i] == arr[i - 1]) 
            curr_count++; 
        else { 
            if (curr_count > max_count) { 
                max_count = curr_count; 
                result = arr[i - 1]; 
            } 
            curr_count = 1; 
        } 
    } 
   
    return result; 
}
