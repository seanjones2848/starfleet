#include "header.h"

int carPosition(unsigned int parkingRow) {
	int ret = 0;

	if (!(parkingRow && ((parkingRow & (parkingRow - 1)) == 0)))
		return -1;
	while (parkingRow != 1) {
		parkingRow = parkingRow >> 1;
		ret = -(~ret);
	}
	return ret;
}
