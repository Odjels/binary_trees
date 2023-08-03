#include "binary_trees.h"

/**
 * visitCurrentLevel - this calls ths func on each node on a level
 * @root: points to the node in the level to call the function in it's nodes
 * @level: the level targeted
 * @func: points to the function to call on each node
 * Return: void
 */
void visitCurrentLevel(binary_tree_t *root, int level, void (*func)(int))
{
	if (root == NULL)
		return;
	if (level == 1)
		func(root->n);
	else if (level > 1)
	{
		visitCurrentLevel(root->left, level - 1, func);
		visitCurrentLevel(root->right, level - 1, func);
	}
}

/**
 * visitLevelOrder - goes through tree using level order traversal
 * @root: root node in the level to traverse
 * @func: function to call on each node
 * Return: Void
 */

void visitLevelOrder(binary_tree_t *root, void (*func)(int))
{
	int high = binary_tree_height(root) + 1;
	int i;

	for (i = 1; i <= high; i++)
		visitCurrentLevel(root, i, func);
}

/**
 * binary_tree_levelorder - goes through a binary tree
 * using level-order traversal
 * @tree: points to the root node of the tree
 * @func: points to a function to call for each node
 * Return: void
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;
	visitLevelOrder((binary_tree_t *)tree, func);
}

/**
 * binary_tree_height - this measures the height of a binary tree
 * @tree: points to the root node of the tree
 * Return: the size or 0 if tree is null
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	int number;

	if (tree == NULL)
		return (0);

	number = tree_height(tree);

	return ((size_t)number);
}

/**
 * tree_height - this count node tree height
 * @node: node to measure
 * Return: height
 */

int tree_height(const binary_tree_t *node)
{
	int leftD, rightD;

	if (node == NULL)
		return (-1);

	leftD = tree_height(node->left);
	rightD = tree_height(node->right);

	if (leftD > rightD)
		return (leftD + 1);
	else
		return (rightD + 1);
}
