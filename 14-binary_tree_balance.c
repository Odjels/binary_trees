#include "binary_trees.h"

/**
 * binary_tree_height - this imeasures the height of a binary tree
 * @tree: point to the root node of the tree
 * Return: the size or 0 if tree is null
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	int count;

	if (tree == NULL)
		return (0);

	count = tree_height(tree);

	return ((size_t)count);
}

/**
 * tree_height - counts the node tree height
 * @node: this is the node to measure
 * Return: height
 */

int tree_height(const binary_tree_t *node)
{
	int left_height, right_height;

	if (node == NULL)
		return (0);

	left_height = tree_height(node->left);
	right_height = tree_height(node->right);

	if (left_height > right_height)
		return (left_height + 1);
	else
		return (right_height + 1);
}


/**
* binary_tree_balance - this function that calculates the balance of a tree
* @tree: The node
* Return: The balance
*/
int binary_tree_balance(const binary_tree_t *tree)
{
	int hright, hleft;

	if (tree == NULL)
		return (0);

	hleft = binary_tree_height(tree->left);
	hright = binary_tree_height(tree->right);

	return (hleft - hright);
}
