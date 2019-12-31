#include "bsTreeNode.h"

BSTreeNode::BSTreeNode()
{
	left = NULL;
	right = NULL;
}

BSTreeNode::BSTreeNode(int key, const char* data, BSTreeNode *left, BSTreeNode *right)
{
	this->key = key;
	this->data = data;
	this->left = left;
	this->right = right;
}

BSTreeNode::~BSTreeNode()
{

}

void BSTreeNode::InOrder()
{

}

void BSTreeNode::PreOrder()
{

}

void BSTreeNode::PostOrder()
{

}


