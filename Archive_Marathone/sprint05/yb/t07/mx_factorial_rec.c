int mx_factorial_rec(int n) {
	if (n >= 12)
		return 0;
	int result = 1;
	if (n == 1)
		return 1;
	result = mx_factorial_rec(n - 1) * n;	
	return result;
}
