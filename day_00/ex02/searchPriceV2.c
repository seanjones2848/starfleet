#include <stdlib.h>
#include <string.h>
#include "header.h"

static int	cmpfunc(const void *a, const void *b) {
	char *s1 = (char*) a;
	struct s_art **s2 = (struct s_art**) b;
	return strcmp(s1, (*s2)->name);
}

int		searchPrice(struct s_art **arts, int n, char *name) {
	struct s_art **ret = (struct s_art**)bsearch(name, arts, n, sizeof(struct s_art*), cmpfunc);
	if (ret)
		return ((*ret)->price);
	return (-1);
}
