#include <stdlib.h>
#include "header.h"

#define BIN(x) ((x) - '0')
#define LENGTH 6

char *getXor(char *a, char *b) {
	char *ret;

	ret = (char*)malloc(sizeof(char) * LENGTH);
	for (int i = 0; i < LENGTH; i++)
		ret[i] = a[i] == b[i] ? '0' : '1';
	return ret;
}

int toInt(char *bits) {
	int ret = 0;
	int base = 1;

	for (int i = LENGTH - 1; i >= 0; i--) {
		ret += base * BIN(bits[i]);
		base *= 2;
	}
	return ret;
}
