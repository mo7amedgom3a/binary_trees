#include "binary_trees.h"
size_t binary_tree_leaves(const binary_tree_t *tree)
{
    int counter = 0;
    if(!tree)
        return 0;
    if (!tree->left && !tree->right)
        counter++;
    binary_tree_leaves(tree->left);
    binary_tree_leaves(tree->right);
    return counter;
}