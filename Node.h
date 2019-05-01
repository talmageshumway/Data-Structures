#ifndef __NODE__
#define __NODE__

#include "Observer.h"
#include <algorithm>
#include <iostream>
using namespace std;

class Node
{
public:
	int value;
	Node* left;
	Node* right;
	Observer observer;	// needed for Unit Testing. Do Not Remove

						// add your code here

	int height;
	Node(int data = -1)
	{
		height = 0;
		value = data;
		left = right = nullptr;
	};
	~Node() = default;
	bool IsLeaf();
	void UpdateHeight();
	int BalanceFactor(Node* cursor);//left height - right height
	//int BalanceFactorHelper(Node* cursor);

};

#endif // __NODE__
