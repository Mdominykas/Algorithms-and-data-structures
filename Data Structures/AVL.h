#ifndef AVL_H_INCLUDED
#define AVL_H_INCLUDED

#include <stdbool.h>


///variable that stores data
///must have comparison operators (<, >)
typedef int VAR;

typedef struct avl_node
{
	VAR data;
	int height;
	struct avl_node *left;
	struct avl_node *right;
	struct avl_node *parent;
} avl_node;

typedef struct avl_tree
{
	avl_node *root;
}avl_tree;

avl_tree* createTree();

bool insert(avl_tree* tree, VAR newVal);

void deleteAVL(avl_node* root);

void traverseAVL(avl_node* root);

int height(avl_node *x);

int balance(avl_node *n);

void printAVL(avl_node *n);

avl_node* find(avl_tree *tree, VAR val);

bool AVLdelete(avl_tree *tree, VAR val);

#endif