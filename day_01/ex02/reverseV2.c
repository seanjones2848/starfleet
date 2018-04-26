#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "header.h"

struct s_stack *stackInit(void) {
	struct s_stack *stack;

	if ((stack = (struct s_stack*)malloc(sizeof(struct s_stack)))) {
		stack->item = NULL;
	}
	return stack;
}

void *pop(struct s_stack *stack) {
	if (stack->item) {
		stack->item = stack->item->next;
		return stack->item;
	}
	return NULL;
}

void push(struct s_stack *stack, char *word) {
	struct s_item *new;

	if ((new = (struct s_item*)malloc(sizeof(struct s_item)))) {
		new->word = word;
		new->next = stack->item;
		stack->item = new;
	}
}

void printReverseV2(struct s_node *lst) {
	struct s_stack *stack;

	stack = stackInit();
	while (lst) {
		push(stack, lst->word);
		lst = lst->next;
	}
	printf("%s", stack->item->word);
	while (pop(stack) != NULL)
		printf(" %s", stack->item->word);
	printf("\n");
}
