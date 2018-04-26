#include <stdio.h>
#include "header.h"

#define INT_SIZE 32

void aloneCan(int *arr, int n) {
	int ret = 0;

	for (int i = 0; i < n; i++)
		ret ^= arr[i];
	printf("%d\n", ret);
}
