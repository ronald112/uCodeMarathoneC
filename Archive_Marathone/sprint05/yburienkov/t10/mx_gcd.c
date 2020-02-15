int mx_gcd(int a, int b) {	
	if (a < 0)
		a *=-1;
	if (b < 0)
		b *=-1;
	if (b == 0)
            return a;
        else
            return mx_gcd (b, a % b);
}

	


/*
int result = 2;
	if (a % result && b & result == 0)
		return result;
	else {
	 
	}
 */
