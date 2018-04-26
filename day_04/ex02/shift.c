#include <stdlib.h>
#include "header.h"

#define BIN(x) ((x) - '0')
#define LENGTH 6

char *leftShift(char *bin, int k) {
	char *ret;

	ret = (char*)malloc(sizeof(char) * LENGTH);
	for (int i = LENGTH - 1; i >= k; i--)
		ret[i - k] = bin[i];
	for (int i = LENGTH - 1; i >= LENGTH - k; i--)
		ret[i] = '0';
	return ret;
}

char *rightShift(char *bin, int k) {
	char bit = bin[0];
	char *ret;

	ret = (char*)malloc(sizeof(char) * LENGTH);
	for (int i = 0; i < LENGTH - k; i++)
		ret[i + k] = bin[i];
	for (int i = 0; i < k; i++)
		ret[i] = bit;
	return ret;
}

int toInt(char *bits) {
	int ret = 0;
	int base = 1;

	for (int i = LENGTH - 1; i > 0; i--) {
		ret += base * BIN(bits[i]);
		base *= 2;
	}
	return bits[0] == '0' ? ret : ret - base;
}
