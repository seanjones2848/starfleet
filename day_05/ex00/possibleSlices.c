#include <stdio.h>
#include "header.h"

int partition(int sum, int big) {
	if (big == 0)
		return 0;
	if (sum == 0)
		return 1;
	if (sum < 0)
		return 0;
	return partition(sum, big - 1) + partition(sum - big, big);
}



void printPossibleSlices(int pizzaSize) {
	printf("%d\n", partition(pizzaSize, pizzaSize));
}
