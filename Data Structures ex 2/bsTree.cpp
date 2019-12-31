#include "bsTree.h"


BSTree::BSTree()
{

}

BSTree::~BSTree()
{

}

void BSTree::MakeEmpty()
{

}
void BSTree::IsEmpty()
{

}

BSTreeNode* BSTree::Find(int key)
{
	BSTreeNode *temp = root;
	while (temp != NULL)
	{
		if (key == temp->key)
		{
			return temp;
		}
		else if (key < temp->key)
		{
			temp = temp->left;
		}
		else
		{
			temp = temp->right;
		}
	}
}
void BSTree::Insert(int key, const char* data)
{
	if (Find(key) != NULL)
	{
		return; //  key already exists;
	}
	BSTreeNode* temp = root;
	BSTreeNode* parent = NULL;
	BSTreeNode* newnode;

	while (temp != NULL)
	{
		parent = temp;
		if (key < temp->key)
		{
			temp = temp->left;
		}
		else temp = temp->right;
	}

	newnode = new BSTreeNode(key, data, NULL, NULL);
	if (parent == NULL)
	{
		root = newnode;
	}
	else if (key < parent->key)
	{
		parent->left = newnode;
	}
	else parent->right = newnode;
}
void BSTree::Delete(int id)
{

}
int BSTree::Min()
{

}
int BSTree::Max()
{

}
void BSTree::PrintTree()
{
	if (root != NULL)
	{
		root->InOrder();
	}
}