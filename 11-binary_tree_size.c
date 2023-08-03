#include "binary_trees.h"

/**
 * binary_tree_size - this measures the size of a binary tree
 * @tree: points to the root node of the tree
 * Return: tree is NULL, else return 0
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t left_count, right_count;

	if (tree == NULL)
		return (0);

	left_count = binary_tree_size(tree->left);
	right_count = binary_tree_size(tree->right);

	return (left_count + right_count + 1);
}
