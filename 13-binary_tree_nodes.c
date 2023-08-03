#include "binary_trees.h"

/**
* binary_tree_nodes - the function that counts non-empty nodes
*
* @tree: the node
* Return: The number of non empty nodes
*/
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	int numb;

	if (tree == NULL)
		return (0);

	numb = 0;

	if ((tree->left || tree->right) && tree)
		numb++;
	numb += (binary_tree_nodes(tree->left) +
		  binary_tree_nodes(tree->right));
	return (numb);
}
