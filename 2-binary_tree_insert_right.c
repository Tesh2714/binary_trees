#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_node_2 - creates a node
 * @parent: parent of the node to create
 * @value: value in new node
 *
 * Return: pointer to the new node
 */
binary_tree_t *binary_tree_node_2(binary_tree_t *parent, int value)
{
	binary_tree_t *nw_node;

	nw_node = malloc(sizeof(binary_tree_t));
	if (nw_node == NULL)
		return (NULL);
	nw_node->parent = parent;
	nw_node->n = value;
	nw_node->left = nw_node->right = NULL;
	return (nw_node);
}

/**
 * binary_tree_insert_right - inserts a node as the right-child
 * @parent: pointer to the node to insert the right-child 
 * @value: value in the new node
 *
 * Description: If parent already has a right-child, the new node must take its
 * place and the old right-child must be set as the right-child of the new node
 *
 * Return: pointer to the created node, or NULL on failure
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *right_child;

	if (parent == NULL)
		return (NULL);
	right_child = binary_tree_node_2(parent, value);
	if (right_child == NULL)
		return (NULL);
	right_child->right = parent->right;
	if (right_child->right != NULL)
		right_child->right->parent = right_child;
	parent->right = right_child;
	return (right_child);
}
