int mx_sqrt(int x) {
	//int result = 0;
	// if (x == 0 || x % 2 != 0)
	// 	return 0;
	// int temp = x;
	// temp /= 2;
	// if (temp % 2 != 0)
	// 	return 0;
	// for (; ((temp * temp) != x) || temp < 0; temp--);
	// if (temp * temp == x)
	// 	return temp;
	
	// return 0;

	if (x == 0)
		return 0;
	int result = x / 2;
	for (;(result >= 0); result--) {
		if ((result * result) == x) {
			return result;
		}
		if (result == 0) 
			return 0;		
	}
	return 0;
}
