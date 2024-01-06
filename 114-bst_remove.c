#include "binary_trees.h"

/**
 * bst_remove - remove a node from a BST tree
 * @root: root of the tree
 * @value: node with this value to remove
 * Return: the tree changed
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *node = NULL;

	if (!root)
		return (NULL);
	if (value > root->n)
		root->right = bst_remove(root->right, value);
	else if (value < root->n)
		root->left = bst_remove(root->left, value);
	else
	{
		if (root->left == NULL)
		{
			node = root->right;
			free(root);
			return (node);
		}
		if (root->right == NULL)
		{
			node = root->left;
			free(root);
			return (node);
		}
		node = minValueNode(root->right);
		root->n = node->n;
		root->right = bst_remove(root->right, node->n);
	}
	return (root);
}

/**
 * minValueNode - get the next successor
 * @root: the right child
 * Return: the min value of this tree
 */
bst_t *minValueNode(bst_t *root)
{
	bst_t *curr = root;

	while (curr->left)
	{
		curr = curr->left;
	}
	return (curr);
}
