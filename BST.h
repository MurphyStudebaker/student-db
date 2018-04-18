#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>

using namespace std;
/**A template implementation of a Binary Search Tree that holds a key seperate from
 	* the data of the node */
template <class T>
class TNode
{
public:
	TNode();
	TNode(int k, T d);
	~TNode();

	int key;
	T data;
	TNode<T> *left;
	TNode<T> *right;
};
template <class T>
TNode<T>::TNode()
{
	key = 0;
	left = NULL;
	right = NULL;
}
template <class T>
TNode<T>::TNode(int k, T d)
{
	key = k;
	data = d;
	left = NULL;
	right = NULL;
}
template <class T>
TNode<T>::~TNode()
{
	// build some character - may or may not be in the book!
}

template <class T>
class BST
{
public:
	BST();
	~BST();

	void insert(int k, T d);
	bool contains(int k);
	bool deleteNode(int k);

	TNode<T> *getMin();
	TNode<T> *getMax();

	bool isEmpty();
	int getSize();
	void print(TNode<T> *node);
	void printTree();
	TNode<T>* getSuccessor(TNode<T> *d);

private:
	TNode<T> *root;
	unsigned int size;
};
template <class T>
BST<T>::BST()
{
	root = NULL;
}
template <class T>
BST<T>::~BST()
{
	// Iterate and deletes
	// Build character along the way
}
template <class T>
void BST<T>::printTree()
{
	print(root);
}

template <class T>
void BST<T>::print(TNode<T> *node) // In-order traversal
{
	if (node == NULL)
	{
		return;
	}
	print(node->left);
	cout << node->data << endl;
	print(node->right);
}
template <class T>
TNode<T>* BST<T>::getMax()
{
	TNode<T> *curr = root;
	if (root == NULL)
	{
		return NULL;
	}
	while (curr->right != NULL)
	{
		curr = curr->right;
	}
	return curr;
}
// get_min is the same, but curr = curr->
template <class T>
void BST<T>::insert(int k, T data)
{
	TNode<T> *node = new TNode<T>(k, data);
	if (root == NULL) // Empty TNode as root
	{
		root = node;
	}
	else // Non-empty tree
	{
		TNode<T> *curr = root;
		TNode<T> *parent = NULL;
		// Now traverse and compare
		while (true)
		{
			parent = curr;
			if (k < curr->key) // Go left
			{
				curr = curr->left;
				if (curr == NULL) // Found the insertion point
				{
					parent->left = node;
					break;
				}
			}
			else // Go right
			{
				curr = curr->right;
				if (curr == NULL) // Found the insertion point
				{
					parent->right = node;
					break;
				}
			}
		}
	}
}
template <class T>
bool BST<T>::contains(int k)
{
	if (root == NULL)
	{
		return false;
	}
	else
	{
		TNode<T> *curr = root;
		while (curr->key != k)
		{
			if (k < curr->key) // Go left
			{
				curr = curr->left;
			}
			else // Go right
			{
				curr = curr->right;
			}
			if (curr == NULL) // Did not find it
			{
				return false;
			}
		}
	}
	return true;
}
template <class T>
bool BST<T>::deleteNode(int k)
{
	if (root == NULL)	// Empty tree
	{
		return false;
	}
	TNode<T> *current = root;
	TNode<T> *parent = root;
	bool is_left;
	// Look for node to be deleted
	while (current->key != k)
	{
		parent = current;
		if (k < current->key)
		{
			is_left = true;
			current = current->left;
		}
		else
		{
			is_left = false;
			current = current->right;
		}
		if (current == NULL) // Node to be deleted does not exist
		{
			return false;
		}
	}
	// We have found what needs to be deleted!
	// 3 cases below: no children, one child, two children
	// No children; easiest case
	if (current->left == NULL && current->right == NULL)
	{
		if (current == root)
		{
			root = NULL;
		}
		else if (is_left)
		{
			parent->left = NULL;
		}
		else
		{
			parent->right = NULL;
		}
	}
	// One child
		// No right child
	else if (current->right == NULL)
	{
		if (current == root)
		{
			root = current->left;
		}
		else if (is_left)
		{
			parent->left = current->left;
		}
		else
		{
			parent->right = current->right;
		}
	}
		// No left child
	else if (current->left == NULL)
	{
		if (current == root)
		{
			root = current->right;
		}
		else if (is_left)
		{
			parent->left = current->right;
		}
		else
		{
			parent->right = current->right;
		}
	}
	// Two children
	else
	{
		TNode<T> *successor = getSuccessor(current);
		if (current == root)
		{
			root = successor;
		}
		else if (is_left)
		{
			parent->left = successor;
		}
		else
		{
			parent->right = successor;
		}
		successor->left = current->left;
	}
	return true;
}
template <class T>
TNode<T>* BST<T>::getSuccessor(TNode<T> *d) // d represents the node that we are going to delete
{
	/* traverse right once from d, and then go all the way left to find the successor */
	TNode<T> *sp = d; // sp = successor's parent
	TNode<T> *successor = d; // successor should be one right, all the way left
	TNode<T> *current = d->right;
	while (current != NULL)
	{
		sp = successor;
		successor = current;
		current = current->left;
	}
	if (successor != d->right) // Not the right child of d
	{
		sp->left = successor->right;
		successor->right = d->right;
	}
	return successor;
}
