void mx_printchar(char c); 

void mx_printint(int n){
    long int sec_n = n;
    long int counter = 0;
    long int max_char = 1;
    int first_res = 0;
    while (sec_n != 0) {
	sec_n /= 10;
	counter++;
        max_char *=10;
    }

    if (n < 0) {
        n *= -1;
	mx_printchar('-');
    }

    for (int sec_coun = 0; sec_coun <= counter; sec_coun++) {	
        first_res = n / max_char;
	if (sec_coun != 0) {
            mx_printchar(first_res+48);
	}
	n = n % max_char;
	max_char /= 10;
    }   
}
