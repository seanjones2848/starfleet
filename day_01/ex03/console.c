#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "header.h"

char	*console(void) {
	struct s_stack *stack;
	char buffer[256];
	char input[256];
	char *ret;

	stack = initStack();
	push(stack, 0);
	while (1) {
		write(1, "?: ", 3);
		fgets(input, 255, stdin);
		input[strlen(input) - 1] = '\0';
		if (strlen(input) == 4 && strcmp(input, "SEND") == 0)
			break;
		else if (strlen(input) == 4 && strcmp(input, "UNDO") == 0) {
			pop(stack);
			for(int b = stack->item->idx ; b <= 255; b++)
				buffer[b] = '\0';
		}
		else {
			sprintf(buffer + stack->item->idx, "%s ", input);
			push(stack, strlen(input) + stack->item->idx + 1);
		}
		printf("%s\n\n", buffer);
	}
	ret = strndup(buffer, stack->item->idx);
	return ret;
}

struct s_stack *initStack(void) {
	struct s_stack *stack;

	if ((stack = (struct s_stack*)malloc(sizeof(struct s_stack)))) {
		stack->item = NULL;
	}
	return stack;
}

int pop(struct s_stack *stack) {
	if (stack->item) {
		stack->item = stack->item->next;
		return stack->item->idx;
	}
	return -1;
}

void push(struct s_stack *stack, int idx) {
	struct s_item *new;

	if ((new = (struct s_item*)malloc(sizeof(struct s_item)))) {
		new->idx = idx;
		new->next = stack->item;
		stack->item = new;
	}
}

