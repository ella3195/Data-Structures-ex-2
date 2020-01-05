#include "bsTree.h"


BSTree::BSTree(BSTreeNode *root) 
{
	this->root = root;
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

BSTreeNode* BSTree::getRoot() {
	return root;
}

BSTreeNode* BSTree::Find(int key)
{
	BSTreeNode *temp = root;
	while (temp != nullptr)
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
	if (Find(key) != nullptr)
	{
		return; //  key already exists;
	}
	BSTreeNode* temp = root;
	BSTreeNode* parent = nullptr;
	BSTreeNode* newnode;

	while (temp != nullptr)
	{
		parent = temp;
		if (key < temp->key)
		{
			temp = temp->left;
		}
		else temp = temp->right;
	}

	newnode = new BSTreeNode(key, data, nullptr, nullptr, parent);
	if (parent == nullptr)
	{
		root = newnode;
	}
	else if (key < parent->key)
	{
		parent->left = newnode;
	}
	else parent->right = newnode;
}

BSTreeNode* BSTree::findMax()
{
	BSTreeNode* max = root;
	while (max->right != nullptr)
		max = max->right;
	return max;
	
}

void BSTree::Delete(BSTreeNode* toDelete)
{
	BSTreeNode* father = toDelete->father;
	if (!(toDelete->left))
	{
		if (toDelete == father->left) {
			father->left = toDelete->right;
		}
		else {
			father->right = toDelete->right;
		}
		if(toDelete->right)
			toDelete->right->father = father; 
	}
	else if (!(toDelete->right))
	{
		if (toDelete == father->left)
			father->left = toDelete->left;
		else
			father->right = toDelete->left;
		if (toDelete->left)
			toDelete->left->father = father;
	}
	else
	{
		swapMaxLeftTree(toDelete);
	}
}

void BSTree::swapMaxLeftTree(BSTreeNode* toDelete)
{
	BSTree leftTree(toDelete->left);
	BSTreeNode* maxLeft = leftTree.findMax();
	toDelete->data = maxLeft->data;
	toDelete->key = maxLeft->key;
	Delete(maxLeft);
}


void BSTree::DeleteRoot()
{
	if (root->left == nullptr)
	{
		root = root->right;
	}
	else if (root->right == nullptr)
	{
		root = root->left;
	}
	else
	{
		swapMaxLeftTree(root);
	}
}

void BSTree::Delete(int id)
{
	BSTreeNode* temp = root;
	if (temp->key == id)
	{
		DeleteRoot();
		return;
	}
	while (temp != nullptr)
	{
		if (temp->key < id)
			temp = temp->right;
		else
			temp = temp->left;
		if (temp->key == id)
		{
			Delete(temp);
			return;
		}
	}
}

void Delete(BSTreeNode* root, int id)
{

}

//int BSTree::Min()
//{
//
//}
//int BSTree::Max()
//{
//
//}
void BSTree::PrintTree()
{
	if (root != nullptr)
	{
		root->InOrder();
	}
}