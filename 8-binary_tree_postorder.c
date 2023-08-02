#include "binary_trees.h"

/**
 * binary_tree_postorder - traverses a binary tree
 * using post-order traversal
 * @tree: points to the root of the tree
 * @func: points to a function to call for each node
 * Return: void
 */

void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;
	func(tree->n);
	binary_tree_postorder(tree->left, func);
	binary_tree_postorder(tree->right, func);
}
