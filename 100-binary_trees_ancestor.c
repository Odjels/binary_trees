#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: points to first node
 * @second: points to the second node
 * Return: points to the lowest common ancestor node
 * of the two given nodes or null
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
									 const binary_tree_t *second)
{
	binary_tree_t *l, *h;
	size_t fid, sid;
	int diff, i = 0;

	if (first == NULL || second == NULL)
		return (NULL);

	fid = binary_tree_depth(first);
	sid = binary_tree_depth(second);

	diff = (int)fid - (int)sid;
	if (diff >= 0)
	{
		l = (binary_tree_t *)first;
		h = (binary_tree_t *)second;
	} else if (diff < 0)
	{
		l = (binary_tree_t *)second;
		h = (binary_tree_t *)first;
		diff *= -1;
	}

	while (i < diff)
	{
		l = l->parent;
		++i;
	}

	while (h != NULL && l != NULL)
	{
		if (h->n == l->n)
			return (h);
		h = h->parent;
		l = l->parent;
	}
	return (NULL);
}

/**
* binary_tree_depth - this function that calculates the height of a node in a tree
*
* @tree: the node
* Return: The depth of the node
*/
size_t binary_tree_depth(const binary_tree_t *tree)
{
	int dleft = 0, dright = 0;

	if (tree == NULL)
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
