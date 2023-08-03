#include "binary_trees.h"

/**
* bst_insert - the function that inserts a new node in search tree
* @tree: The root node
* @value: new node's value
* Return: The new node
*/

bst_t *bst_insert(bst_t **tree, int value)
{
	int dupl = 0;
	bst_t *now;

	if (tree == NULL)
		return (NULL);
	dupl = bs_tree_preorder((*tree), value);
	if (dupl == 0)
		return (NULL);
	if ((*tree) == NULL)
	{
		(*tree) = now = binary_tree_node((*tree), value);
		return (now);
	}
	if (value == (*tree)->n)
		return (NULL);
	if (value < (*tree)->n)
	{
		if ((*tree)->left == NULL)
		{
			now = (*tree)->left = binary_tree_node((*tree), value);
			return (now);
		}
		now = bst_insert(&(*tree)->left, value);
		return (now);
	}
	else if (value > (*tree)->n)
	{
		if ((*tree)->right == NULL)
		{
			now = binary_tree_node((*tree), value);
			(*tree)->right = now;
			return (now);
		}
		now = bst_insert(&(*tree)->right, value);
		return (now);
	}
	if ((*tree) == NULL)
		return (NULL);
	return (*tree);
}

/**
 * bs_tree_preorder - through a binary tree
 * using pre-order traversal to find duplicate
 * @tree: points to the root node
 * @n: the value to check for
 * Return: 0 for true or 1 for false
 */

int bs_tree_preorder(bst_t *tree, int n)
{
	int lef, rit;

	if (tree == NULL)
		return (1);

	if (tree->n == n)
		return (0);

	lef = bs_tree_preorder(tree->left, n);
	rit = bs_tree_preorder(tree->right, n);
	return (lef * rit);
}
