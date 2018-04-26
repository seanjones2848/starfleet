#include "header.h"

int occupiedPlaces(unsigned int parkingRow) {
	int ret = 0;
	while (parkingRow) {
		ret = -(~ret);
		parkingRow = (parkingRow - 1) & parkingRow;
	}
	return ret;
}
