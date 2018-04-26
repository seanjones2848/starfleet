#include <stdlib.h>
#include "header.h"

int *bits(int bit, int l) {
	int *bin = (int*)malloc(sizeof(int) * l);
	int base = 1;

	for (int i = 0; i < l; i++) {
		bin[i] = (bit & base) / base;
		base *= 2;
	}
	return bin;
}

int **pianoDecompress(struct s_bit *bit, int l) {
	int **ret = (int**)malloc(sizeof(int*) * l);

	for (int i = 0; i < bit->n; i++)
		ret[i] = bits(bit->arr[i], l);
	return ret;
}
