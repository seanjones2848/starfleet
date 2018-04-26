#include "header.h"

int leftmostCar(unsigned int parkingRow) {
	int ret = 0;
	while (parkingRow && parkingRow != 1) {
		parkingRow = parkingRow >> 1;
		ret = -(~ret);
	}
	return parkingRow == 1 ? ret : -1;
}
