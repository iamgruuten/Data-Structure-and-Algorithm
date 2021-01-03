// BST.cpp
#include<iostream>
using namespace std;

#include "BST.h"
#define max(x,y) ((x > y)? x : y)

// constructor
BST::BST()
{
	root = NULL;
}

// search an item in the binary search tree
BinaryNode* BST::search(ItemType target)
{
	return search(root, target);
}

BinaryNode* BST::search(BinaryNode* t, ItemType target)
{
	if (t == NULL)		// item not found
		return NULL;
	else
	{
		if (t->item == target)	// item found
			return t;
		else
			if (target < t->item)
				return search(t->left, target); 	// search in left subtree
			else
				return search(t->right, target);  	// search in right subtree
	}
}

// insert an item to the binary search tree
void BST::insert(ItemType item)
{
	insert(root, item);
}

void BST::insert(BinaryNode*& t, ItemType item)
{
	if (t == NULL)
	{
		BinaryNode* newNode = new BinaryNode;
		newNode->item = item;
		newNode->left = NULL;
		newNode->right = NULL;
		t = newNode;
	}
	else
		if (item < t->item)
			insert(t->left, item);  	// insert in left subtree
		else
			insert(t->right, item); 	// insert in right subtree
}

// traverse the binary search tree in inorder
void BST::inorder()
{
	if (isEmpty())
		cout << "No item found" << endl;
	else
		inorder(root);
}

void BST::inorder(BinaryNode* t)
{
	if (t != NULL)
	{
		inorder(t->left);
		cout << t->item << endl;
		inorder(t->right);
	}
}

// traverse the binary search tree in preorder
void BST::preorder()
{
	if (isEmpty())
		cout << "No item found" << endl;
	else
		preorder(root);
}

void BST::preorder(BinaryNode* t)
{
	if (t != NULL)
	{
		cout << t->item << endl;
		preorder(t->left);
		preorder(t->right);
	}
}

// traverse the binary search tree in postorder
void BST::postorder()
{
	if (isEmpty())
		cout << "No item found" << endl;
	else
		postorder(root);
}

void BST::postorder(BinaryNode* t)
{
	if (t != NULL)
	{
		postorder(t->left);
		postorder(t->right);
		cout << t->item << endl;
	}
}

// check if the binary search tree is empty
bool BST::isEmpty() { return (root == NULL); }

// delete an item from the binary search tree
void BST::remove(ItemType target) { remove(root, target); }

void BST::remove(BinaryNode*& t, ItemType item)
{
	if (t != NULL)
	{
		if (item < t->item)			// search in left subtree
			remove(t->left, item);
		else if (item > t->item)	// search in right subtree
			remove(t->right, item);
		else						// item == t->item (found) - base case
		{
			if (t->left == NULL && t->right == NULL) // case 1 : node has 0 child
			{
				BinaryNode* temp = t;	// node to be deleted
				t = NULL;
				delete temp;			// delete the node
			}
			else if (t->left == NULL)	// case 2 : node has 1 child
			{
				BinaryNode* temp = t;	// node to be deleted
				if (t == root)			// current node is root
					root = t->right;
				else
					t = t->right;
				delete temp;			// delete the node
			}
			else if (t->right == NULL)	// case 2 : node has 1 child
			{
				BinaryNode* temp = t;	// node to be deleted
				if (t == root)			// current node is root
					root = t->left;
				else
					t = t->left;
				delete temp;			// delete the node
			}
			else 						// case 3 : node has 2 children
			{
				BinaryNode* successor = t->left;
				while (successor->right != NULL)	// search for right most node in left sub-tree
					successor = successor->right;
				ItemType item = successor->item;
				remove(t->left, item);	// delete the successor (either case 1 or case 2)
				t->item = item;			// replace the node’s item with that of the successor
			}
		}
	}
}

// ---------------- to be implemented -------------------

// count the number of nodes in the binary search tree
int BST::countNodes() {
	return countNodesR(root);
}

//Iterative method
int BST::countNodes(BinaryNode* t)
{
	int level = 0;
	int totalNodes = 0;
	if (t != NULL) {
		BinaryNode* currNode = t;

		while (currNode != NULL) {
			level++;
			currNode = currNode->left;
		}
		currNode = t;

		// Check for full Binary tree
		for (int i = 0; i < level; i++) {
			if (currNode->right == NULL) {
				if (i + 1 == level)
					return (pow(2, level) - 1);
				else
					break;
			}
			currNode = currNode->right;
		}

		totalNodes += (pow(2, level - 1) - 1);

		int right = pow(2, level - 1) - 1;
		int left = 0;
		int medium = (left + right) / 2;

		while (left <= right) {
			currNode = root;
			int l = 0;
			int r = pow(2, level - 1) - 1;
			int m = (l + r) / 2;

			while (l <= r && currNode != NULL) {
				if (m >= medium) {
					currNode = currNode->left;
					r = m - 1;
				}
				else {
					currNode = currNode->right;
					l = m + 1;
				}
				m = (l + r) / 2;
			}

			if (currNode != NULL)
				left = medium + 1;
			else
				right = medium - 1;

			medium = (left + right) / 2;
		}
		totalNodes += left;
	}

	return totalNodes;
}

//Recursive method
int BST::countNodesR(BinaryNode* t)
{
	int count = 1;

	if (t == NULL) {
		return count;
	}
	else
	{
		count += countNodes(t->left);
		count += countNodes(t->right);
		return count;
	}
}

// compute the height of the binary search tree
int BST::getHeight() {
	return getHeight(root);
}

int BST::getHeight(BinaryNode* t)
{
	if (t == NULL) {
		return -1;
	}

	int left = getHeight(t->left);
	int right = getHeight(t->right);

	if (left > right) {
		return left + 1;
	}
	else {
		return right + 1;
	}
}

// check if the binary search tree is balanced
bool BST::isBalanced() {
	return isBalanced(root);
}

bool BST::isBalanced(BinaryNode* t)
{
	if (t == NULL) {
		return true;
	}

	//The property of a balance tree must be less than 1

	return isBalanced(t->right) && isBalanced(t->left) && abs(getHeight(t->left) - getHeight(t->right)) <= 1;
}