#include <stdlib.h>

#define LENGTH 4
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

char *tilde(char *bits) {
	if (bits[0] == '~') {
		for (int i = 1; i - 1 < LENGTH; i++)
			bits[i] = bits[i] == '0' ? '1' : '0';
		return bits + 1;
	}
	return (bits);
}


char *getAnd(char *a, char *b) {
	char *ret;
	int A;
	int B;

	a = tilde(a);
	b = tilde(b);
	ret = (char*)malloc(sizeof(char) * LENGTH);
	for (int i = LENGTH - 1; i >= 0; i--) {
		A = BIT(a[i]);
		B = BIT(b[i]);
		ret[i] = (A & B) + '0';
	}
	return ret;
}

char *getOr(char *a, char *b) {
	char *ret;
	int A;
	int B;

	a = tilde(a);
	b = tilde(b);
	ret = (char*)malloc(sizeof(char) * LENGTH);
	for (int i = LENGTH - 1; i >= 0; i--) {
		A = BIT(a[i]);
		B = BIT(b[i]);
		ret[i] = (A | B) + '0';
	}
	return ret;
}
