#include <stdlib.h>
#include <string.h>
#include "header.h"

char *precious(int *text, int size) {
	struct s_node *head;
	struct s_node *current;
	struct s_node *next;
	char *ret;
	int i = 1;
	int j = 0;
	int sign = 0;

	ret =(char*)malloc(sizeof(char) *size);
	if ((head = (struct s_node*)malloc(sizeof(struct s_node)))) {
		head->c = CS[0];
		head->next = NULL;
		head->prev = NULL;
	}
	current = head;
	while (i < (int)strlen(CS)) {
		if ((next = (struct s_node*)malloc(sizeof(struct s_node)))) {
			next->c = CS[i];
			next->prev = current;
			next->next = NULL;
		}
		current->next = next;
		current = next;
		i++;
	}
	head->prev = current;
	current->next = head;
	i = 0;
	while (i < size) {
		sign = text[i] < 0 ? -1 : 1;
		j = sign * text[i];
		while (j > 0) {
			if (sign == 1)
				head = head->next;
			else
				head = head->prev;
			j--;
		}
		j = 0;
		ret[i] = head->c;
		i++;
	}
	return ret;
}
