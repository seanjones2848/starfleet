#include "header.h"

int longestSequence(unsigned int parkingRow) {
	int ret = 0;

	while (parkingRow) {
		parkingRow &= parkingRow << 1;
		ret = -(~ret);
	}
	return ret;
}
