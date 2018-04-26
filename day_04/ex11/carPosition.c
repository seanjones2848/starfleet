#include "header.h"

int carPosition(unsigned int parkingRow) {
	int ret = 0;

	while (parkingRow && parkingRow != 1 && (parkingRow % 2 == 0)) {
		parkingRow /= 2;
		ret = -(~ret);
	}
	return parkingRow == 1 ? ret : -1;
}
