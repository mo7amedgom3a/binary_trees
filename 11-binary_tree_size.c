#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: tree to measure the size of
 *
 * Return: size of the tree
 *         0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
    int counter = 0;
	if (!tree)
		return (0);
    counter = binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1;
    return counter;
}
