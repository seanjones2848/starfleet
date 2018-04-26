#include "header.h"

int getPlace(unsigned int parkingRow, int pos) {
	return ((1 << pos) & parkingRow) >> pos;
}
