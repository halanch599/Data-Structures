// TreeApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <queue>

using namespace std;

struct Node {
	int    data;
	Node*  left;
	Node * right;
};

class Tree
{
public:
	Node * root;
	Tree();
	bool isEmpty();
	Node* createNode(int);
	void insert(int);
	Node* Delete(Node *r, int data);
	//Node * removeRecursive(Node *r, int val);
	void preorderTraversal(Node*);
	void inorderTraversal(Node*);
	void postorderTraversal(Node*);
	void LevelOrder(Node* root);
	int	 height(Node* node);
	void printLevel(Node* root, int level);
	void search(int element);
	Node* findMax(Node*);
	Node* findMin(Node*);
	Node *parent(int);
	void print(Node *p, int start);
};

Tree::Tree()
{
	root = NULL;
}

void Tree::preorderTraversal(Node *temp)
{
	if (temp == NULL)
		return;
	cout << temp->data << " ";
	preorderTraversal(temp->left);
	preorderTraversal(temp->right);
}
void Tree::inorderTraversal(Node *temp)
{
	if (temp == NULL)
		return;	
	inorderTraversal(temp->left);
	cout << temp->data << " ";
	inorderTraversal(temp->right);
}
void Tree::postorderTraversal(Node *temp)
{
	if (temp == NULL)
		return;
	postorderTraversal(temp->left);
	postorderTraversal(temp->right);
	cout << temp->data << " ";
}
void Tree::insert(int element)
{
	if (root==NULL)
	{
		root = createNode(element);
	}
	else
	{
		Node *temp, *parent;
		temp = root;
		parent = NULL;

		while (temp!=NULL)
		{
			parent = temp;
			temp = element < temp->data ? temp->left : temp->right;
		}

		temp = createNode(element);
		if (element < parent->data)
			parent->left = temp;
		else
			parent->right = temp;
	}
}
void remove(int element)
{

}
//Node * Tree::removeRecursive(Node *r, int val)
//{
//	Node *temp;
//	//if r is null return
//	if (r == NULL)
//		return NULL;
//	// if data is less then r then search in left subtree
//	if (val < r->data)
//		r->left = removeRecursive(r->left, val);
//	// if data is greater then r then search in right subtree
//	else if (val > r->data)
//		r->right = removeRecursive(r->right, val);
//	// if data is found at r then delete it
//	else
//	{
//		
//		if ((r->left == NULL) && (r->right == NULL))
//		{
//			delete r;
//			r = NULL;
//			return r;
//		}
//		else
//			// if r has 1 right child
//			if (r->left == NULL)
//			{
//				// 1 right child
//				temp = r;
//				r = r->right;
//				delete temp;
//				temp = NULL;
//				return r;
//			}
//			else
//				// if r has 1 left child
//				if (r->right == NULL)
//				{
//					temp = r;
//					r = r->left;
//					delete temp;
//					temp = NULL;
//					return r;
//				}
//				// 1 left child and 1 right child
//				else
//				{
//					/*
//					// Find the maxmimum node in the left subtree 
//					maxNode = findMax(r->left);
//					int val = maxNode->data;
//					r = removeRecursive(r, val);
//					r->data = val;
//					*/
//					
//					// or find min in right sub tree
//					//Find the maxmimum node in the left subtree 
//					Node * tempnode = findMin(r->right);
//					r->data = tempnode->data;
//					r->right = removeRecursive(r, tempnode->data);
//				}
//	}
//
//	return r;
//}
Node* Tree::Delete(Node *r, int data) {
	if (r == NULL) 
		return r;
	else if (data < r->data) 
		r->left = Delete(r->left, data);
	else if (data > r->data) 
		r->right = Delete(r->right, data);
	// Element to delete if found 
	else {
		// Case 1:  No child
		if (r->left == NULL && r->right == NULL) {
			delete r;
			r = NULL;
		}
		//Case 2: One child 
		else if (r->left == NULL) {
			Node *temp = r;
			r = r->right;
			delete temp;
			temp = NULL;
		}
		else if (r->right == NULL) {
			Node *temp = r;
			r = r->left;
			delete temp;
			temp = NULL;
		}
		// case 3: 2 children
		else {
			// in the left subtree find maximum
			Node *temp = findMax(r->left);
			r->data = temp->data;
			r->left = Delete(r->left, temp->data);
			/*
			// in the right subtree find minimum
			Node *temp = findMin(r->right);
			r->data = temp->data;
			r->right = Delete(r->right, temp->data);
			*/
		}
	}
	return r;
}
Node * Tree::parent(int element)
{
	Node * temp = root;
	Node*parent = NULL;
	bool found = false;

	while (temp != NULL)
	{
		if (element == temp->data)
		{
			found = true;
			break;
		}
		else
		{
			parent = temp;
			if (element < temp->data)
				temp = temp->left;
			else
				temp = temp->right;
		}
	}
	// if element is not found or is root then 
	// set parent to null to indicate no parent
	if (!found)
		parent = NULL;

	return parent;
}
void Tree::search(int element)
{
	Node * temp = root;
	bool found = false;
	while (temp != NULL)
	{
		if (element == temp->data)
		{
			found = true;
			break;
		}
		else
		{
			if (element < temp->data)
				temp = temp->left;
			else
				temp = temp->right;
		}
	}
	if (found)
	{
		cout << element << " found" << endl;
	}
	else
	{
		cout << element << " Not found" << endl;
	}
}
Node* Tree::findMax(Node *r)
{
	while (r->right != NULL)
		r = r->right;
	return r;
}
Node* Tree::findMin(Node *r)
{
	while (r->left != NULL) 
		r= r->left;
	return r;
}
Node* Tree::createNode(int element)
{
	Node *temp = new Node;
	temp->data = element;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}


bool Tree::isEmpty()
{
	return root == NULL;
}

void inorder(Node* currentNode)
{
	if (currentNode) {
		inorder(currentNode->left);
		cout << currentNode->data;
		inorder(currentNode->right);
	}
}
void preorder(Node* currentNode)
{
	if (currentNode) {
		cout << currentNode->data;
		preorder(currentNode->left);
		preorder(currentNode->right);
	}
}

int Tree::height(Node* node)
{
	if (node == NULL)
		return 0;
	else
	{
		/* compute the height of each subtree */
		int lheight = height(node->left);
		int rheight = height(node->right);

		/* use the larger one */
		if (lheight > rheight)
			return(lheight + 1);
		else 
			return(rheight + 1);
	}
}

void Tree::LevelOrder(Node* root)
{
	int h = height(root);
	int i;
	for (i = 1; i <= h; i++)
	{
		printLevel(root, i);
		cout << endl;
	}
}

/* Print nodes at a given level */
void Tree::printLevel(Node* root, int level)
{
	if (root == NULL)
		return;
	if (level == 1)
		cout<<root->data <<" ";
	else if (level > 1)
	{
		printLevel(root->left, level - 1);
		printLevel(root->right, level - 1);
	}
}
void Tree::print(Node *p, int start)
{
	start++;
	if (p->right != NULL)
	{
		print(p->right, start);
	}
	for (int i = 0; i <= start; i++)
	{
		cout << "    ";
	}
	cout << p->data << endl;
	if (p->left != NULL)
	{
		print(p->left, start);
	}
}

void print2DUtil(Node *root, int space)
{
	// Base case 
	if (root == NULL)
		return;

	// Increase distance between levels 
	space += COUNT;

	// Process right child first 
	print2DUtil(root->right, space);

	// Print current node after space 
	// count 
	printf("\n");
	for (int i = COUNT; i < space; i++)
		printf(" ");
	printf("%d\n", root->data);

	// Process left child 
	print2DUtil(root->left, space);
}

int main()
{
	Tree t;
	t.insert(20);
	t.insert(10);
	t.insert(30);
	t.insert(5);
	t.insert(12);
	t.insert(25);
	t.insert(35);
	t.insert(21);
	t.insert(28);
	t.insert(32);
	t.insert(40);

	t.preorderTraversal(t.root); cout << endl;
	cout << endl;
	t.inorderTraversal(t.root); cout << endl;
	cout << endl;
	t.postorderTraversal(t.root); cout << endl;
	cout << endl;
	t.LevelOrder(t.root);
	cout << endl;

	//t.search(305);

	//cout <<"Max "<< t.findMax(t.root)->data<<endl;
	//cout <<"Min "<< t.findMin(t.root)->data << endl;
	//cout << "Parent " << t.parent(35)->data << endl;
	t.root= t.Delete(t.root, 20);
	t.root = t.Delete(t.root, 32);
	t.LevelOrder(t.root);
	cout << endl << endl << endl;
	//cout << endl << t.root->data << endl;
	t.print(t.root, 0);
	system("pause");
}




//
//void Tree::printPostorder(Node* node)
//{
//	if (node == NULL)
//		return;
//
//	// first recur on left subtree 
//	printPostorder(node->left);
//
//	// then recur on right subtree 
//	printPostorder(node->right);
//
//	// now deal with the node 
//	cout << node->data << " ";
//}
//
///* Given a binary tree, print its nodes in inorder*/
//void Tree::printInorder(Node* node)
//{
//	if (node == NULL)
//		return;
//
//	/* first recur on left child */
//	printInorder(node->left);
//
//	/* then print the data of node */
//	cout << node->data << " ";
//
//	/* now recur on right child */
//	printInorder(node->right);
//}
//
///* Given a binary tree, print its nodes in preorder*/
//void Tree::printPreorder(Node* node)
//{
//	if (node == NULL)
//		return;
//
//	/* first print data of node */
//	cout << node->data << " ";
//
//	/* then recur on left sutree */
//	printPreorder(node->left);
//
//	/* now recur on right subtree */
//	printPreorder(node->right);
//}
