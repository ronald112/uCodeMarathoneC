int mx_gcd(int a, int b);

int mx_lcm(int a, int b) {
	if (a < 0)
		a *=-1;
	if (b < 0)
		b *=-1;
	int result = a * b;
	result /= mx_gcd(a, b);
	return result;
}
