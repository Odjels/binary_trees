#include "binary_trees.h"
/**
 * aux_sort - this creates the tree using the half element of the array
 * @parent: parent of the node to create
 * @array: sorted array
 * @begin: the position where the array starts
 * @last: the position where the array ends
 * Return: tree created
 */
avl_t *aux_sort(avl_t *parent, int *array, int begin, int last)
{
	avl_t *root;
	binary_tree_t *haux;
	int mide = 0;

	if (begin <= last)
	{
		mide = (begin + last) / 2;
		haux = binary_tree_node((binary_tree_t *)parent, array[mid]);
		if (haux == NULL)
			return (NULL);
		root = (avl_t *)haux;
		root->left = haux_sort(root, array, begin, mide - 1);
		root->right = haux_sort(root, array, mide + 1, last);
		return (root);
	}
	return (NULL);
}
/**
 * sorted_array_to_avl - this creates a alv tree from sorted array
 * @array: sorted array
 * @size: size of the sorted array
 * Return: alv tree form sorted array
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);
	return (haux_sort(NULL, array, 0, ((int)(size)) - 1));
}
