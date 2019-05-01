#pragma once
#include "Node.h"

class AVLTree
{
public:
	AVLTree();
	~AVLTree();

	void Insert(int data);
	Node* Search(int data);
	void InorderTraversal();
	void PreOrderTraversal();
	void Print();
	int Size();
	Node * root;
	Node* GetRoot() { return root; };

	Node* Rebalance(Node* cursor);
	Node* RotateLeft(Node* cursor);
	Node* RotateRight(Node* cursor);

private:
	void DestructorHelper(Node* cursor);
	Node* InsertHelper(Node* cursor, int data);
	Node* SearchHelper(Node* cursor, int data);
	void InorderHelper(Node* cursor);
	void PreOrderTraversalHelper(Node* cursor);
	void PrintHelper(Node* cursor, string offset);
	int SizeHelper(Node* cursor);
};

