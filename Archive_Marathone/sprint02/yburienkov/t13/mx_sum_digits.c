int mx_sum_digits(int num) {
    int some_num = 0;
    int sum = 0;
    while (num != 0) {
    some_num = num % 10;
    if (some_num < 0) {
        some_num *= -1;
        }
    num /= 10;
    sum += some_num; 
    }
    return sum;
}
