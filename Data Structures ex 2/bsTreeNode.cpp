#include "bsTreeNode.h"

BSTreeNode::BSTreeNode()
{
	key = 0;
	data = 0;
	left = nullptr;
	right = nullptr;
	father = nullptr;
}

BSTreeNode::BSTreeNode(int key, const char* data, BSTreeNode *left, BSTreeNode *right, BSTreeNode* father)
{
	this->key = key;
	this->data = data;
	this->left = left;
	this->right = right;
	this->father = father;
}

BSTreeNode::~BSTreeNode()
{

}

void BSTreeNode::InOrder()
{
	BSTreeNode* temp = this;
	if (temp)
	{
		temp->left->InOrder();
		cout << "(Key: " << temp->key << ", Data: " << temp->data << ") ";
		temp->right->InOrder();
	}
}

void BSTreeNode::PreOrder()
{
	BSTreeNode* temp = this;
	if (temp)
	{
		temp->left->InOrder();
		temp->right->InOrder();
		cout << "(Key: " << temp->key << ", Data: " << temp->data << ") ";
	}
}

void BSTreeNode::PostOrder()
{
	BSTreeNode* temp = this;
	if (temp)
	{
		cout << "(Key: " << temp->key << ", Data: " << temp->data << ") ";
		temp->left->InOrder();
		temp->right->InOrder();
	}
}


