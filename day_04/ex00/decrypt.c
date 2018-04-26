#include <stdlib.h>

#define LENGTH 6
#define BIT(x) ((x) - '0')

int toInt(char *bits) {
	int ret = 0;
	int base = 1;

	for (int i = LENGTH - 1; i >= 0; i--) {
		ret += base * BIT(bits[i]);
		base *= 2;
	}
	return ret;
}

char *getSum(char *a, char *b) {
	char *ret;
	int car = 0;
	int A;
	int B;

	ret = (char*)malloc(sizeof(char) * LENGTH);
	for (int i = LENGTH - 1; i >= 0; i--) {
		A = BIT(a[i]);
		B = BIT(b[i]);
		if (A == 1 && B == 1) {
			ret[i] = '1';
			car = 1;
		}
		else if (car == 1 && (A == 0 && B == 0)) {
			ret[i] = '1';
			car = 0;
		}
		else if (A == 1 || B == 1)
			ret[i] = '1';
		else
			ret[i] = '0';
	}
	return ret;
}
