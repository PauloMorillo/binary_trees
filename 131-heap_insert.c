#include <stdlib.h>
#include "binary_trees.h"
#include <stdio.h>
#include "binary_trees.h"

/**
 * heap_insert - Function to insert a node for a binary tree
 * @root: this is the head of our binary tree
 * @value: This is the value of each element in our binary tree
 * Return: pointer to new node or NULL if it fails
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new = NULL;
	binary_tree_t *parent = NULL;

	if (*root)
	{
		/* recorrer */
		parent = chooseparent(*root);
		/* agregar */
		if (parent->left && parent->right == NULL)
		{
			parent->right = binary_tree_node(parent, value);
			new = parent->right;
		}

		if (parent->left == NULL && parent->right == NULL)
		{
			parent->left = binary_tree_node(parent, value);
			new = parent->left;
		}
		/* verificar */
		new = verify_order(new);
	}
	else
	{
		*root = binary_tree_node(*root, value);
		new = *root;
	}
	return (new);
}


/**
 * chooseparent - function to choose parent node to insert
 * @tree: pointer to the root node of the tree
 * Return: return parent node
 */
binary_tree_t *chooseparent(binary_tree_t *tree)
{
	int a = 0, b = 0;

	a = binary_tree_size(tree->left);
	b = binary_tree_size(tree->right);

	if (a <= b)
	{
		if (tree->left)
			return (chooseparent(tree->left));
	}
	else if (a > b && binary_tree_is_perfect(tree->left) == 0)
	{
		if (tree->left)
			return (chooseparent(tree->left));
	}
	else
	{
		if (tree->right)
			return (chooseparent(tree->right));
	}
	return (tree);
}

/**
 * binary_tree_size - This function returns the size of the tree
 * @tree: root of tree
 * Return: returns the size
 */
int binary_tree_size(const binary_tree_t *tree)
{
	/* int c = 0; */
	int a = 0;
	/* int b = 0; */

	if (tree)
	{
		a = a + 1;
		if (tree->left)
		{
			a = a + (binary_tree_size(tree->left));
		}
		if (tree->right)
		{
			a = a + (binary_tree_size(tree->right));
		}
		return (a);
	}
	return (0);
}


/**
 * verify_order - returns node position
 * @tree: root of tree
 * Return: returns the balance
 */
binary_tree_t *verify_order(binary_tree_t *tree)
{
	int temp = 0;

	if (tree)
	{
		if (tree->parent)
		{
			if (tree->parent->n < tree->n)
			{
				temp = tree->n;
				tree->n = tree->parent->n;
				tree->parent->n = temp;
				return (verify_order(tree->parent));
			}
		}
	}
	return (tree);
}

/**
 * binary_tree_is_perfect - returns 1 if the tree is full or 0 if not
 * @tree: root of tree
 * Return: returns the balance
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int h = 0;
	int ful = 1;
	int h2 = 0;
	int fulpo = 0;

	if (tree)
	{
		h = binary_tree_heighta(tree);
		while (h > 0)
		{
			ful = 1;
			h2 = h;
			while (h2 > 0)
			{
				ful = ful * (2);
				h2 = h2 - 1;
			}
			fulpo = fulpo + ful;
			h = h - 1;
		}
		if (fulpo + 1 == binary_tree_size(tree))
			return (1);
	}
	return (0);
}
