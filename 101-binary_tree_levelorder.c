#include "binary_trees.h"
#define MAX_Q_SIZE 500

/**
 * binary_tree_levelorder - Traverse a binary tree using level-order traversal.
 * @tree: Pointer to the root of the binary tree.
 * @func: Pointer to a function to call for each node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int rear, front;

	if (!tree)
		return;

	binary_tree_t **queue = createQueue(&front, &rear);
	binary_tree_t *current_node = (binary_tree_t *)tree;

	while (current_node)
	{
		// Process the current node
		func(current_node->n);

		// Enqueue left child if exists
		if (current_node->left)
			enQueue(queue, &rear, current_node->left);

		// Enqueue right child if exists
		if (current_node->right)
			enQueue(queue, &rear, current_node->right);

		// Move to the next node in the level-order traversal
		current_node = deQueue(queue, &front);
	}
}

/**
 * createQueue - Create a queue for level-order traversal.
 * @front: Pointer to the front of the queue.
 * @rear: Pointer to the rear of the queue.
 * @return: Pointer to the created queue.
 */
binary_tree_t **createQueue(int *front, int *rear)
{
	binary_tree_t **queue = malloc(sizeof(binary_tree_t *) * MAX_Q_SIZE);

	*front = *rear = 0;
	return (queue);
}

/**
 * enQueue - Enqueue a node into the queue.
 * @queue: Pointer to the queue.
 * @rear: Pointer to the rear of the queue.
 * @new_node: Pointer to the node to be enqueued.
 */
void enQueue(binary_tree_t **queue, int *rear, binary_tree_t *new_node)
{
	queue[*rear] = new_node;
	(*rear)++;
}

/**
 * deQueue - Dequeue a node from the queue.
 * @queue: Pointer to the queue.
 * @front: Pointer to the front of the queue.
 * @return: Dequeued node.
 */
binary_tree_t *deQueue(binary_tree_t **queue, int *front)
{
	(*front)++;
	return queue[*front - 1];
}
