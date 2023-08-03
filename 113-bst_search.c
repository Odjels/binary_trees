#include "binary_trees.h"

/**
* bst_search - the function that searches for a node
*
* @tree: tree root
* @value: value to match
* Return: The node containing the value
*/
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree == NULL)
		return (NULL);

	if (tree->n == value)
		return ((bst_t *)tree);

	if (tree->n < value)
		return (bst_search(tree->right, value));

	if (tree->n > value)
		return (bst_search(tree->left, value));

	return (NULL);
}
