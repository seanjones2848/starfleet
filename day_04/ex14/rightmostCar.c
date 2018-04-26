#include "header.h"

int rightmostCar(unsigned int parkingRow) {
	int ret = 0;

	while (parkingRow != 0) {
		if (((parkingRow >> ret) & 1) == 1)
			return ret;
		ret = -(~ret);
	}
	return -1;
}
