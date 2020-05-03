#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_node - This function creates a binary tree node
 * @parent: node to add new node
 * @value: value to insert in new node
 * Return: poointer to the new node
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *newnode;

	newnode = malloc(sizeof(binary_tree_t));
	if (newnode == NULL)
		return (NULL);

	newnode->n = value;
	newnode->parent = parent;
	newnode->left = NULL;
	newnode->right = NULL;
	return (newnode);
}

/**
 * binary_tree_heighta - measures the height of a binary tree
 * @tree: root of tree
 * Return: returns the height of the node
 */
int binary_tree_heighta(const binary_tree_t *tree)
{
	int a = 0;
	int b = 0;
	/* int c = 0; */

	if (tree)
	{
		if (tree->left)
			a = (1 + binary_tree_heighta(tree->left));
		if (tree->right)
			b = (1 + binary_tree_heighta(tree->right));
		if (a < b)
			return (b);
		else
			return (a);
	}
	return (0);
}
