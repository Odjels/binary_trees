#include "binary_trees.h"

/**
 * binary_tree_node - this creates a binary node
 * @parent: points to parent of the node to be created
 * @value: the value stored in the new node
 * Return: points to the new node or Null if failed
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_Nod = malloc(sizeof(binary_tree_t));

	if (new_Nod == NULL)
		return (NULL);

	new_Nod->n = value;
	new_Nod->left = NULL;
	new_Nod->right = NULL;
	new_Nod->parent = parent;
	return (new_Nod);
}
