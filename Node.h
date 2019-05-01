#ifndef __NODE__
#define __NODE__

#include <algorithm>
#include <iostream>
using namespace std;

class Node
{
public:
	int value;
	Node* left;
	Node* right;

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
};

#endif // __NODE__
