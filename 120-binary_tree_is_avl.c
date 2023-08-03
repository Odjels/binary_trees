#include "binary_trees.h"

/**
 * binary_tree_is_avl - this finds if a binary tree is an avl
 * @tree: points to the root node of the tree
 *
 * Return: 1 if tree is avl
 *         0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (btia_helper(tree, INT_MIN, INT_MAX));
}

/**
 * btia_helper - helps to find if a binary tree is an avl
 * @tree: points to the root node of the tree
 * @min: the min value
 * @max: the max value
 *
 * Return: 1 if tree is avl
 *         0 otherwise
 */
int btia_helper(const binary_tree_t *tree, int min, int max)
{
	int side_l, side_r;

	if (!tree)
		return (1);
	if (tree->n < min || tree->n > max)
		return (0);

	side_l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	side_r = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	if (abs(side_l - side_r) > 1)
		return (0);

	return (btia_helper(tree->left, min, tree->n - 1) &&
		btia_helper(tree->right, tree->n + 1, max));
	/* This checks the BST logic */
}

/**
 * binary_tree_height - this measures the height of a binary tree
 * @tree: the tree to measure the height of
 *
 * Return: height of the tree
 *         0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t h_left = 0;
	size_t h_right = 0;

	if (!tree)
		return (0);

	h_left = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	h_right = tree->right ? 1 + binary_tree_height(tree->right) : 0;
	return (h_left > h_right ? h_left : h_right);
}
