#include "binary_trees.h"
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
    binary_tree_t* NewNode = malloc(sizeof(binary_tree_t));
    if(!NewNode)
        return NULL;
    NewNode->parent = parent;
    NewNode->n = value;
    NewNode->left = NewNode->right = NULL;
    return NewNode;
}