#include "binary_trees.h"

/**
 * binary_tree_insert_left - this Inserts a node as the left-child
 *
 * @parent: A pointer to where to insert the left-child in
 * @value: The value to store in the new node
 *
 * Return: Null if the parent is Null or if it fails to create
 * a new node, else it returns a pointer to the newely created node.
 *
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_Nod;

	if (parent == NULL)
		return (NULL);

	new_Nod = binary_tree_node(parent, value);
	if (new_Nod == NULL)
		return (NULL);

	if (parent->left != NULL)
	{
		new_Nod->left = parent->left;
		parent->left->parent = new_Nod;
	}
	parent->left = new_Nod;

	return (new_Nod);
}
