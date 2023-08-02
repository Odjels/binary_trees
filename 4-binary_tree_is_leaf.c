#include "binary_trees.h"

/**
 * binary_tree_is_leaf - checks if the node is a leaf
 * @node: points to the node to check
 * Return: return 1 if node is a leaf, otherwise 0
 *
 */

int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (!node)
		return (0);
	if (node->left != NULL)
		return (0);
	else if (node->right != NULL)
		return (0);
	return (1);
}
