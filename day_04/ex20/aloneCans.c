#include <stdio.h>
#include "header.h"

void aloneCans(int *arr, int n) {
	int xor = arr[0];
	int bit;
	int ret[2];

	for (int i = 1; i < n; i++)
		xor ^= arr[i];
	bit = xor & ~(xor - 1);
	for (int i = 0; i < n; i++) {
		if (arr[i] & bit)
			ret[0] ^= arr[i];
		else
			ret[1] ^= arr[i];
	}
	printf("%d\n%d\n", ret[1], ret[0]);
}
