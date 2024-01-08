#include "binary_trees.h"

int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return 1;

	int left_height = binary_tree_height(tree->left);
	int right_height = binary_tree_height(tree->right);

	if (abs(left_height - right_height) > 1)
		return 0;

	return binary_tree_is_avl(tree->left) && binary_tree_is_avl(tree->right);
}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: tree to measure the height of
 *
 * Return: height of the tree
 *         0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_l = 0;
	size_t height_r = 0;

	if (!tree)
		return 0;

	height_l = tree->left ? 1 + binary_tree_height(tree->left) : 1;
	height_r = tree->right ? 1 + binary_tree_height(tree->right) : 1;

	return (height_l > height_r ? height_l : height_r);
}
