#include "binary_trees.h"

/**
 * binary_tree_height - this measures the height of a binary tree
 * @tree: points to the root node of the tree
 * Return: the size or 0 if tree is null
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	int count;

	if (!tree)
		return (0);

	count = tree_height(tree);
	return ((size_t)count);
}

/**
 * tree_height - count nodes for tree height
 * @node: node to measure
 * Return: height
 */

int tree_height(const binary_tree_t *node)
{
	int left_heigth, right_heigth;

	if (node == NULL)
		return (-1);

	left_heigth = tree_height(node->left);
	right_height = tree_height(node->right);

	if (left_height> right_height)
		return (left_heigth + 1);
	else
		return (right_heigth + 1);
}
