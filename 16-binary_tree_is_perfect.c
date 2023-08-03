#include "binary_trees.h"

/**
 * binary_tree_size - this measures the size of a binary tree
 * @tree: points to the root node of the tree
 * Return: tree is NULL, the function will return 0
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t lnumb, rnumb;

	if (tree == NULL)
		return (0);

	lnumb = binary_tree_size(tree->left);
	rnumb = binary_tree_size(tree->right);

	if (lnumb == rnumb)
		return (lnumb + rnumb + 1);
	else
		return (0);
}

/**
* binary_tree_is_perfect - this function that checks if a tree is perfect
* @tree: The tree ion
* Return: 0 or 1
*/
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (FALSE);

	if (binary_tree_size(tree) > 0)
		return (1);
	else
		return (0);
}
