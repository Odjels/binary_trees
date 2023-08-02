#include "binary_trees.h"

/**
 * binary_tree_insert_right - this inserts a node as the
 * right-child
 * @parent: points to the node to insert the right-child in
 * @value: value to store in the new node
 * Return: a pointer to the created node
 * or NULL on failure or if parent is NULL
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_Nod = malloc(sizeof(binary_tree_t));

	if (new_Nod == NULL)
		return (NULL);
	if (!parent)
	{
		free(new_Nod);
		return (NULL);
	}

	new_Nod->n = value;
	new_Nod->right = NULL;
	new_Nod->left = NULL;
	new_Nod->parent = parent;

	if (parent->right == NULL)
	{
		parent->right = new_Nod;
	}
	else
	{
		new_Nod->right = parent->right;
		parent->right->parent = new_Nod;
		parent->right = new_Nod;
	}
	return (new_Nod);
}
