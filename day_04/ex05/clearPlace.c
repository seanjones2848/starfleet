#include "header.h"

unsigned int clearPlace(unsigned int parkingRow, int pos) {
	if ((((1 << pos) & parkingRow) >> pos) == 1)
		return 1 << pos ^ parkingRow;
	return parkingRow;
}
