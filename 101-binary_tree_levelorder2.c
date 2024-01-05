#include "binary_trees.h"

/**
 * binary_tree_levelorder - traverst a binary tree using level-order traverse
 * @tree: tree to traverse
 * @func: pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t level, maxlevel;

	if (!tree || !func)
		return;

	maxlevel = binary_tree_height(tree);

	for (level = 1; level <= maxlevel; level++)
		printCurrentLevel((binary_tree_t *)tree, func, level);
}

/**
 * printCurrentLevel - goes through a binary tree level by level
 * @tree: tree to traverse
 * @func: pointer to a function to call for each node
 * @level: the level of the tree to call func upon
 */
void printCurrentLevel(const binary_tree_t *tree, void (*func)(int), size_t level)
{
	if (level == 1)
                func(tree->n);
	else
	{
		printCurrentLevel((binary_tree_t *)tree->left, func, level - 1);
		printCurrentLevel((binary_tree_t *)tree->right, func, level - 1);
	}
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
		return (0);

	height_l = tree->left ? 1 + binary_tree_height(tree->left) : 1;
	height_r = tree->right ? 1 + binary_tree_height(tree->right) : 1;
	return (height_l > height_r ? height_l : height_r);
}
