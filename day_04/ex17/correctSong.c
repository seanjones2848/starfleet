#include "header.h"

void correctSong(struct s_bit *bit, int l, int row, int col, int dist) {
	for (int i = 0; i < dist; i++)
		bit->arr[i + row] = 1 << col;
	l = 0;
}
