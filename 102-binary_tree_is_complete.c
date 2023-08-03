#include "binary_trees.h"

/**
 * createQueue - this creates a queue
 * @front: points to the front of the queue
 * @rear: points to rear of the queue
 * Return: points to queue
 */

binary_tree_t **createQueue(int *front, int *rear)
{
	binary_tree_t **Dqueue =
	(binary_tree_t **)malloc(sizeof(binary_tree_t *) * 500);

	*front = *rear = 0;
	return (Dqueue);
}

/**
 * enQueue - enQueue the new node
 * @queue: pointer to pointer to queue
 * @rear: pointer to rear of the queue
 * @new_node: pointer to the new node
 * Return: void
 */

void enQueue(binary_tree_t **queue, int *rear, binary_tree_t *new_node)
{
	queue[*rear] = new_node;
	(*rear)++;
}

/**
 * deQueue - deQueue the front node
 * @queue: points to pointer to queue
 * @front: points to front of the queue
 * Return: deQueueed node
 */

binary_tree_t *deQueue(binary_tree_t **queue, int *front)
{
	(*front)++;
	return (queue[*front - 1]);
}

/**
 * isQueueEmpty - this checks if the queue is empty
 * @front: points to front of the queue
 * @rear: points to rear fo the queue
 * Return: TRUE or FALSE
 */

int isQueueEmpty(int *front, int *rear)
{
	return (*rear == *front);
}

/**
 * binary_tree_is_complete - this checks if a binary tree is complete
 * @tree: points to the root node of the tree
 * Return: 1 or 0
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	binary_tree_t *root = (binary_tree_t *)tree;
	binary_tree_t **queue;
	int rear, front, blag;

	if (tree == NULL)
		return (0);

	queue = createQueue(&front, &rear);
	blag = FALSE;
	enQueue(queue, &rear, root);
	while (!isQueueEmpty(&front, &rear))
	{
		binary_tree_t *temp_node = deQueue(queue, &front);
		/* Checking for left child is present*/
		if (temp_node->left)
		{
			if (blag == TRUE)
			{
				free(queue);
				return (FALSE);
			}
			enQueue(queue, &rear, temp_node->left);
		}
		else
			blag = TRUE;
		/* Checking if right child is present*/
		if (temp_node->right)
		{
			if (blag == TRUE)
			{
				free(queue);
				return (FALSE);
			}
			enQueue(queue, &rear, temp_node->right);
		}
		else
			blag = (TRUE);
	}
	free(queue);
	return (TRUE);
}
