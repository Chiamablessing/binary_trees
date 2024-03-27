#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Left-rotates a binary tree.
 * @tree: A pointer to the root node of the tree to rotate.
 *
 * Return: A pointer to the new root node after rotation.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *rot, *tmp;

	if (tree == NULL || tree->right == NULL)
		return (tree);

	rot = tree->right;
	tmp = rot->left;
	rot->left = tree;
	tree->right = tmp;

	rot->parent = tree->parent;
	tree->parent = rot;

	if (tmp != NULL)
		tmp->parent = tree;

	if (rot->parent != NULL)
	{
		if (rot->parent->left == tree)
			rot->parent->left = rot;
		else
			rot->parent->right = rot;
	}
	return (rot);
}
