#include "Node.h"

bool Node::IsLeaf()
{
	if (left == nullptr and right == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Node::UpdateHeight()
{
	int leftH = -1;
	int rightH = -1;
	if (left != nullptr)
	{
		leftH = left->height;
	}
	if (right != nullptr)
	{
		rightH = right->height;
	}
	height = max(rightH, leftH) + 1;
}

int Node::BalanceFactor(Node* cursor)
{
	//if nullptr children
	int H;
	if (cursor->left == nullptr && cursor->right == nullptr)
	{
		H = 0;
	}
	else if (cursor->left == nullptr)
	{
		H = -1 - cursor->right->height;
	}
	else if (cursor->right == nullptr)
	{
		H = cursor->left->height + 1;
	}
	else
	{
		H = cursor->left->height - cursor->right->height;
	}
	return H;
}

