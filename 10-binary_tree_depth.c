#include <stdio.h>
#include "binary_trees.h"

/**
* binary_tree_depth - this calculates the height of a node in a tree
*
* @tree: points to the node
* Return: The depth of the node
*/
size_t binary_tree_depth(const binary_tree_t *tree)
{
	int dleft = 0, dright = 0;

	if (!tree)
	return (0);

	if (tree->parent)
	{
		dleft = binary_tree_depth(tree->parent) + 1;
		dright = binary_tree_depth(tree->parent) + 1;
	}

	if (dleft > dright)
		return (dleft);
	else
		return (dright);
}
