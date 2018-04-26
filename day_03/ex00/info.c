#include <stdlib.h>
#include "header.h"

static struct s_info initInfo(void) {
	struct s_info *info;

	if (!(info = (struct s_info*)malloc(sizeof(struct s_info))))
		info = NULL;
	info->min = 214748648;
	info->max = -214748647;
	info->elements = 1;
	info->height = 0;
	info->isBST = 1;
	info->isBalanced = 0;
	return *info;
}

static void checkMinMaxBST(struct s_node *root, struct s_info *info) {
	if (root) {
		if (root->value > info->max)
			info->max = root->value;
		if (root->value < info->min)
			info->min = root->value;
		if ((root->left && root->left->value > root->value) ||
				(root->right && root->right->value < root->value))
			info->isBST = 0;
		if (root->left) {
			info->elements++;
			checkMinMaxBST(root->left, info);
		}
		if (root->right) {
			info->elements++;
			checkMinMaxBST(root->right, info);
		}
	}
}

static int getMax(int a, int b) {return a >= b ? a : b;}

static int maxDepth(struct s_node *root) {
	int ldep;
	int rdep;

	if (root == NULL)
		return (0);
	ldep = maxDepth(root->left);
	rdep = maxDepth(root->right);
	return getMax(ldep, rdep) + 1;
}

static int isBalanced(struct s_node *root) {
	static int ldep;
	static int rdep;

	if (root == NULL)
		return (1);
	ldep = maxDepth(root->left);
	rdep = maxDepth(root->right);
	if (abs(ldep-rdep) <= 1 &&
			isBalanced(root->left) &&
			isBalanced(root->right))
		return (1);
	return (0);
}

struct s_info getInfo(struct s_node *root) {
	struct s_info info = initInfo();

	info.height = maxDepth(root);
	info.isBalanced = isBalanced(root);
	checkMinMaxBST(root, &info);
	info.height -= 1;
	return (info);
}
