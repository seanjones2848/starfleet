#include <stdlib.h>
#include "header.h"

static struct s_node *initNode(int n) {
	struct s_node *node = NULL;

	if ((node = (struct s_node*)malloc(sizeof(struct s_node)))) {
		node->value = n;
		node->left = NULL;
		node->right = NULL;
	}
	return node;
}

struct s_node *addNode(int *arr, int start, int end) {
	int mid;
	struct s_node *root;

	if (start > end)
		return NULL;
	mid = (start + end) / 2;
	root = initNode(arr[mid]);
	root->left = addNode(arr, start, mid - 1);
	root->right = addNode(arr, mid + 1, end);
	return root;
}

struct s_node *createBST(int *arr, int n) {
	return addNode(arr, 0, n);
}
