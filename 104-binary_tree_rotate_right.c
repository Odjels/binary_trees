#include "binary_trees.h"

/**
* binary_tree_rotate_right - this function rotates a tree rightward
*
* @tree: The root node
* Return: The new root
*/
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *temp, *gag;

	if (tree == NULL || tree->left == NULL)
		return (NULL);

	temp = tree;
	gag = tree->parent;
	tree = tree->left;

	if (tree->right)
	{
		temp->left = tree->right;
		tree->right->parent = temp;
	}
	else
		temp->left = NULL;
	temp->parent = tree;
	tree->right = temp;

	if (gag != NULL)
		gag->left = tree;
	tree->parent = gag;

	return (tree);
}
