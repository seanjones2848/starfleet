#include "header.h"

unsigned int updatePlace(unsigned int parkingRow, int pos, int value) {
	return ((value << pos) | (parkingRow & ~(1 << pos)));
}
