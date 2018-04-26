#include <stdlib.h>
#include <stdio.h>
#include "header.h"

struct s_node *initNode(int value, struct s_node *random) {
	struct s_node *new;

	if ((new = (struct s_node*)malloc(sizeof(struct s_node)))) {
		new->value = value;
		new->random = random;
		new->next = NULL;
	}
	return new;
}

struct s_node *cloneGameBoard(struct s_node *node) {
	struct s_node *clone;
	struct s_node *tmp;
	struct s_node *head;
	struct s_node *ref;

	head = initNode(node->value, node->random);
	clone = head;
	ref = node;
	while (ref->next) {
		ref = ref->next;
		tmp = initNode(ref->value, ref->random);
		clone->next = tmp;
		clone = clone->next;
	}
	clone = head;
	while (clone->next) {
		ref = head;
		if (clone->random) {
			while (ref->next && clone->random && ref->value != clone->random->value)
				ref = ref->next;
			clone->random = ref;
		}
		clone = clone->next;
	}
	return head;
}
