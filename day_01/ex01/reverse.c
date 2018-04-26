#include "header.h"
#include <stdio.h>

void printReverse(struct s_node *lst) {
	static int q = 0;
	if (lst) {
		q++;
		printReverse(lst->next);
		q--;
		printf("%s", lst->word);
		if (q > 0)
			printf(" ");
		else
			printf("\n");
	}
}
