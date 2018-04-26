#include <string.h>
#include <stdlib.h>
#include "header.h"

static int	cmpfunc(const void *a, const void *b) {
	struct s_art **s1 = (struct s_art**) a;
	struct s_art **s2 = (struct s_art**) b;
	return strcmp((*s1)->name, (*s2)->name);
}

void sortArts(struct s_art **arts) {
	int i = 0;

	while (arts[i])
		i++;
	qsort((void*)arts, i, sizeof(struct s_art*), cmpfunc);
}
