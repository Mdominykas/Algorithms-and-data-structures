#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include "AVL.h"


static void leftRotate(avl_tree *tree, avl_node *x);

static void rightRotate(avl_tree *tree, avl_node *x);

static void avlDeleteFixup(avl_tree *tree, avl_node *n);

///https://www.codesdope.com/course/data-structures-avl-trees/

///creates a new tree
avl_tree* createTree()
{
	avl_tree *tree = malloc(sizeof(avl_tree));
	tree->root = NULL;
	return tree;
}


///creates a new node
static avl_node* createNode(VAR val)
{
	avl_node *node = (avl_node*) malloc(sizeof(avl_node));
	if(node == NULL)
		return NULL;
	node->data = val;
	node->left = NULL;
	node->right = NULL;
	node->parent = NULL;
	node->height = 0;
}

static VAR Max(VAR a, VAR b)
{
	if(a > b)
		return a;
	return b;
}

///inserts newVal in to tree
bool insert(avl_tree* tree, VAR newVal)
{
	avl_node *temp = tree->root;
	if(temp == NULL)
	{
		tree->root = createNode(newVal);
		return true;
	}

	avl_node *par;
	while (temp != NULL)
	{
		par = temp;
		if(newVal < temp->data)
			temp = temp->left;
		else if (newVal > temp->data)
			temp = temp->right;
		else
			return false;
	}

	avl_node *newNode;

	if(newVal < par->data)
	{
		par->left = createNode(newVal);
		newNode = par->left;
	}
	else if (newVal > par->data)
	{
		par->right = createNode(newVal);
		newNode = par->right;
	}
	else
		return false;

	temp = newNode;

	newNode->parent = par;

	avl_node *child = newNode;

	while(par != NULL)
	{
		par->height = 1 + Max(height(par->left), height(par->right));
		avl_node *grandPar = par->parent;


		if((balance(grandPar) <= -2) || (2 <= balance(grandPar)))
		{
			if(par == grandPar->left)
			{
				if(child == grandPar->left->left)
				{
					rightRotate(tree, grandPar);
				}
				else if (child == grandPar->left->right)
				{
					leftRotate(tree, par);
					rightRotate(tree, grandPar);
				}
			}
			else if (par == grandPar->right)
			{
				if(child == grandPar->right->right)
				{
					leftRotate(tree, grandPar);
				}
				else if (child == grandPar->right->left)
				{
					rightRotate(tree, par);
					leftRotate(tree, grandPar);
				}
			}
			break;
		}

		child = child->parent;
		par = par->parent;

	}

	return true;

}

static void leftRotate(avl_tree *tree, avl_node *par)
{
	avl_node *child = par->right;

	child->parent = par->parent;
	if(par->parent == NULL)
		tree->root = child;
	else if (par->parent->right == par)
		par->parent->right = child;
	else
		par->parent->left = child;
	par->parent = child;

	if(child->left != NULL)
		child->left->parent = par;
	par->right = child->left;
	
	child->left = par;

	par->height = 1 + Max(height(par->left), height(par->right));
	child->height = 1 + Max(height(child->left), height(child->right));
}

static void rightRotate(avl_tree *tree, avl_node *par)
{
	avl_node *child = par->left;

	child->parent = par->parent;
	if(par->parent == NULL)
		tree->root = child;
	else if (par->parent->right == par)
		par->parent->right = child;
	else
		par->parent->left = child;
	par->parent = child;

	if(child->right != NULL)
		child->right->parent = par;
	par->left = child->right;

	child->right = par;

	par->height = 1 + Max(height(par->left), height(par->right));
	child->height = 1 + Max(height(child->left), height(child->right));
}

/// function that deletes entire tree given root node 
void deleteAVL(avl_node *root)
{
	if(root == NULL)
		return;
	if(root->left != NULL)
		deleteAVL(root->left);
	if(root->right != NULL);
		deleteAVL(root->right);
	free(root);
}

/// function that traverse entire subtree given of given node
void traverseAVL(avl_node *node)
{
	if(node == NULL)
		return;
	if(node->left != NULL)
	{
		traverseAVL(node->left);
	}
	printf("%d ", node->data);
	if(node->right != NULL)
	{
		traverseAVL(node->right);
	}
}

///function that return smallest larger node element
///or null if such element does not exist
avl_node* next(avl_node *node)
{
	while(node != NULL)
	{
		if(node->right != NULL)
		{
			node = node->right;
			break;
		}
		node = node->parent;
	}
	if(node == NULL)
		return node;

	while(node->left != NULL)
		node = node->left;
	return node;
}


///leaf node v is transplanted into u place
static void transplant(avl_tree *tree, avl_node *dest, avl_node *source)
{


	if(dest->parent == NULL)
		tree->root = source;
	else if  (dest->parent->left == dest)
	{
		dest->parent->left = source;
		dest->parent->height = 1 + Max(height(dest->parent->left), height(dest->parent->right));
	}
	else
	{
		dest->parent->right = source;
		dest->parent->height = 1 + Max(height(dest->parent->left), height(dest->parent->right));
	}


	if(source != NULL)
	{
		source->parent = dest->parent;
		source->height = 1 + Max(height(source->left), height(source->right));
	}


}

static void avlDeleteFixup(avl_tree *tree, avl_node *node)
{
	while(node != NULL)
	{
		node->height = 1 + Max(height(node->left), height(node->right));

		if((balance(node) <= -2) || (2 <= balance(node)))
		{
			avl_node *grandPar = node;
			avl_node *par;
			if(height(grandPar->left) > height(grandPar->right))
				par = grandPar->left;
			else
				par = grandPar->right;

			avl_node *child;

			if(height(par->left) > height(par->right))
				child = par->left;
			else if (height(par->left) < height(par->right))
				child = par->right;
			else
			{
				if(par == grandPar->left)
					child = par->left;
				else
					child = par->right;
			}

			if(par == grandPar->left)
			{
				if(child == par->left)
					rightRotate(tree, grandPar);
				else
				{
					leftRotate(tree, par);
					rightRotate(tree, grandPar);
				}
			}
			else
			{
				if(child == par->right)
					leftRotate(tree, grandPar);
				else
				{
					rightRotate(tree, par);
					leftRotate(tree, grandPar);
				}
			}
		}
		node = node->parent;
	}
}

bool AVLdelete(avl_tree *tree, VAR val)
{
	avl_node *node = find(tree, val);
	if(node == NULL)
		return false;

	if(node->left == NULL)
	{
		transplant(tree, node, node->right);
		avlDeleteFixup(tree, node);

		free(node);
	}
	else if (node->right == NULL)
	{
		//printAVL(n);
		transplant(tree, node, node->left);
		avlDeleteFixup(tree, node);
		
		free(node);
	}
	else if((node->left != NULL) && (node->right != NULL))
	{

        avl_node* minLarger = next(node);
        if (minLarger->parent != node)
        {
            transplant(tree, minLarger, minLarger->right);
            minLarger->right = node->right;
            minLarger->right->parent = minLarger;
        }
        transplant(tree, node, minLarger);
        minLarger->left = node->left;
        minLarger->left->parent = minLarger;
        if (minLarger != NULL)
            avlDeleteFixup(tree, minLarger);
        free(node);

	}

	return true;
}

///returns node with given value val
avl_node* find(avl_tree *tree, VAR val)
{
	avl_node *currentNode = tree->root;
	while(currentNode != NULL)
	{
		if(currentNode->data == val)
			return currentNode;
		else if (val < currentNode->data)
			currentNode = currentNode->left;
		else
			currentNode = currentNode->right;
	}
	return NULL;
}

///prints entire subtree of given node n
void printAVL(avl_node *node)
{
	if(node == NULL)
		return;
	printf("%d :", node->data);
	if(node->left != NULL)
		printf("left = %d ", node->left->data);
	if(node->right != NULL)
		printf("right = %d ", node->right->data);
	printf("height = %d ", height(node));
	printf("balance = %d \n", balance(node));

	if(node->left != NULL)
		printAVL(node->left);
	if(node->right != NULL)
		printAVL(node->right);
}

///function that returns height of subtree rooted at node
int height(avl_node *node)
{
	if(node == NULL)
		return -1;
	return node->height;
}

///function that returns difference between height of
///right and left subtree
int balance(avl_node *node)
{
	if(node == NULL)
		return 0;
	return height(node->right) - height(node->left);
}