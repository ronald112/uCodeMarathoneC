//mx_pow.c

double mx_pow(double n, unsigned int pow) {
    double result = 1;
    for (int i = 0; i < (int)pow; i++) {
        result *= n;
    }
    return result; 
}
