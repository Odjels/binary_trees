#include "binary_trees.h"

/**
 * bal - this Measures balance factor of a AVL
 * @tree: the tree to go through
 * Return: balanced factor
 */
void bal(avl_t **tree)
{
	int bfac;

	if (tree == NULL || *tree == NULL)
		return;
	if ((*tree)->left == NULL && (*tree)->right == NULL)
		return;
	bal(&(*tree)->left);
	bal(&(*tree)->right);
	bfac = binary_tree_balance((const binary_tree_t *)*tree);
	if (bfac > 1)
		*tree = binary_tree_rotate_right((binary_tree_t *)*tree);
	else if (bval < -1)
		*tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}
/**
 * successor - this gets the next successor i mean the min node in the right subtree
 * @node: the tree to check
 * Return: the min value of this tree
 */
int successor(bst_t *node)
{
	int left = 0;

	if (node == NULL)
	{
		return (0);
	}
	else
	{
		left = successor(node->left);
		if (left == 0)
		{
			return (node->n);
		}
		return (left);
	}

}
/**
 *remove_type - this function that removes a node depending of its children
 *@root: node to remove
 *Return: 0 if it has no children or other value if it has
 */
int remove_type(bst_t *root)
{
	int new_val = 0;

	if (!root->left && !root->right)
	{
		if (root->parent->right == root)
			root->parent->right = NULL;
		else
			root->parent->left = NULL;
		free(root);
		return (0);
	}
	else if ((!root->left && root->right) || (!root->right && root->left))
	{
		if (!root->left)
		{
			if (root->parent->right == root)
				root->parent->right = root->right;
			else
				root->parent->left = root->right;
			root->right->parent = root->parent;
		}
		if (!root->right)
		{
			if (root->parent->right == root)
				root->parent->right = root->left;
			else
				root->parent->left = root->left;
			root->left->parent = root->parent;
		}
		free(root);
		return (0);
	}
	else
	{
		new_val = successor(root->right);
		root->n = new_val;
		return (new_val);
	}
}
/**
 * bst_remove - this removes a node from a BST tree
 * @root: root of the tree
 * @value: node with the value to remove
 * Return: the tree changed
 */
bst_t *bst_remove(bst_t *root, int value)
{
	int typ = 0;

	if (root == NULL)
		return (NULL);
	if (value < root->n)
		bst_remove(root->left, value);
	else if (value > root->n)
		bst_remove(root->right, value);
	else if (value == root->n)
	{
		typ = remove_type(root);
		if (typ != 0)
			bst_remove(root->right, typ);
	}
	else
		return (NULL);
	return (root);
}

/**
 * avl_remove - this removes a node from a AVL tree
 * @root: the root of the tree
 * @value: node with this value to remove
 * Return: the tree changed
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *root_b = (avl_t *) bst_remove((bst_t *) root, value);

	if (root_b == NULL)
		return (NULL);
	bal(&root_b);
	return (root_b);
}
