double mx_pow_rec(double n, unsigned int pow) {	
	if (pow == 0)
		return 0;
	if (pow == 1)
		return n;
	n *= mx_pow_rec(n, pow - 1);		
	return n;
}
