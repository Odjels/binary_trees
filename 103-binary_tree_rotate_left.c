#include "binary_trees.h"

/**
* binary_tree_rotate_left - this function rotates a tree leftward
*
* @tree: The root node
* Return: The new root
*/
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *temp, *gag;

	if (tree == NULL || tree->right == NULL)
		return (NULL);

	temp = tree;
	gag = tree->parent;
	tree = tree->right;

	if (tree->left)
	{
		temp->right = tree->left;
		tree->left->parent = temp;
	}
	else
	{
		temp->right = NULL;
	}
	temp->parent = tree;
	tree->left = temp;

	if (gag != NULL)
	{
		gag->right = tree;
		tree->parent = gag;
	}

	return (tree);
}
