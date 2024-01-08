#include "binary_trees.h"

/**
 * bst_remove - Remove a node from a BST tree.
 * @root: Root of the tree.
 * @value: Node with this value to remove.
 * Return: The tree after removing the desired value.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	if (!root)
		return (NULL);

	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (root->left == NULL)
		{
			bst_t *temp = root->right;

			free(root);
			return (temp);
		}
		else if (root->right == NULL)
		{
			bst_t *temp = root->left;

			free(root);
			return (temp);
		}

		bst_t *successor = root->right;

		while (successor->left != NULL)
			successor = successor->left;

		root->n = successor->n;

		/*Remove the in-order successor*/
		root->right = bst_remove(root->right, successor->n);
	}

	return (root);
}
