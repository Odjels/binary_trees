#include "binary_trees.h"

/**
* binary_tree_sibling - this function that finds the sibling of a node
*
* @node: the node
* Return: the node's sibling
*/
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *siblin;

	if (node == NULL || node->parent == NULL ||
	   node->parent->right == NULL ||
	   node->parent->left == NULL)
		return (NULL);

	if (node == node->parent->left)
		siblin = node->parent->right;
	else if (node == node->parent->right)
		siblin = node->parent->left;
	return (siblin);
}
