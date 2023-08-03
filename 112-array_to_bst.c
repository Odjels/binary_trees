#include "binary_trees.h"

/**
 * array_to_bst - builds a Binary Search Tree from an array
 * @array: pointer to the first element in the array
 * @size: number of elements in the array
 * Return: pointer to the root node of the created bst or null
 */

bst_t *array_to_bst(int *array, size_t size)
{
	int a;
	bst_t *root_nod = NULL;

	if (array != NULL)
	{
		for (a = 0; a < (int)size; a++)
		{
			bst_insert(&root_nod, *(array + a));
		}
	}
	return (root_nod);
}
