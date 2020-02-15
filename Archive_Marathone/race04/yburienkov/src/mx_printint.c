void mx_printchar();

void mx_printint(int n) {
    if (n == -2147483648) {
	mx_printint(214748364);
	mx_printchar(8 + 48);
    }
    else  {
	if (n < 0) {
	    mx_printchar('-'); 
	    n = -n;
	}
	if (n > 9) {
	    mx_printint(n / 10);
	    mx_printchar((n % 10) +48);
	}
	if (n < 10){
	    mx_printchar(n + 48);
	}

    }
}
