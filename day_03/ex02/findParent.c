#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "header.h"

static struct s_list *initList(struct s_node *node, int depth) {
	struct s_list *list;

	if ((list = (struct s_list*)malloc(sizeof(struct s_list)))) {
		list->node = node;
		list->depth = depth;
		list->next = NULL;
		return list;
	}
	return NULL;
}

void walk(struct s_node *root, int idx, struct s_list *list) {
	static int depth = 1;

	if (!root)
		return;
	else {
		list->next = initList(root, depth);
		idx = 0;
		depth++;
		while (root->children[idx]) {
			walk(root->children[idx], idx, list->next);
			idx++;
		}
		depth--;
		idx = 0;
	}
	return;
}


struct s_node *findParent(struct s_node *root, char *firstSpecies, char *secondSpecies) {
	struct s_list *head;
	struct s_node *ret;
	int depth;

	head = initList(NULL, 0);
	walk(root, 0, head);
	while (head->next && (strcmp(firstSpecies, head->node->name) != 0 &&
				strcmp(secondSpecies, head->node->name) != 0))
		head = head->next;
	depth = head->depth;
	while (head->next && (strcmp(firstSpecies, head->node->name) != 0 &&
				strcmp(secondSpecies, head->node->name) != 0)) {
		if (head->depth < depth) {
			depth = head->depth;
			ret = head->node;
		}
		head = head->next;
	}
	return ret;
}
