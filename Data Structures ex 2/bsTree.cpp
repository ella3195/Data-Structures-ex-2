#include "bsTree.h"


BSTree::BSTree(BSTreeNode *root) 
{
	this->root = root;
}

BSTree::~BSTree()
{
	freeTree(root);
}

void BSTree::freeTree(BSTreeNode *root)
{
	if (!root)
		return;
	freeTree(root->left);
	freeTree(root->right);
	delete root;
}

void BSTree::MakeEmpty()
{
	freeTree(root);
	root = nullptr;
}

bool BSTree::IsEmpty()
{
	return root == nullptr;
}

BSTreeNode* BSTree::getRoot()
{
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
	if (!(toDelete->left)) //no left son
	{
		if (toDelete == father->left) //deleting a left son
			father->left = toDelete->right;
		else //deleting a right son
			father->right = toDelete->right;
		if (toDelete->right) //updating the son's father
			toDelete->right->father = father;
		delete toDelete;
	}
	else if (!(toDelete->right))//no right son
	{
		if (toDelete == father->left)
			father->left = toDelete->left;
		else
			father->right = toDelete->left;
		if (toDelete->left)
			toDelete->left->father = father;
		delete toDelete;
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
	BSTreeNode* temp = root;
	if (root->left == nullptr)
	{
		root = root->right;
		delete temp;
	}
	else if (root->right == nullptr)
	{
		root = root->left;
		delete temp;
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

int BSTree::Min()
{
	BSTreeNode* min = root;
	while (min->left != nullptr)
		min = min->left;
	return min->key;
}

int BSTree::Max()
{
	BSTreeNode* max = root;
	while (max->right != nullptr)
		max = max->right;
	return max->key;
}

void BSTree::PrintTree()
{
	if (root != nullptr)
	{
		root->InOrder();
	}
	cout << endl;
}

int BSTree::Succ(int key)
{
	BSTreeNode* temp = Find(key);
	if (temp->right)
	{
		BSTree rightTree(temp->right);
		return rightTree.Min();
	}
	else
	{
		while (temp != root)
		{
			if (temp == temp->father->left)
				return temp->father->key;
			temp = temp->father;
		}
	}
	return 0;
}

int BSTree::Pred(int key)
{
	BSTreeNode* temp = Find(key);
	if (temp->left)
	{
		BSTree leftTree(temp->left);
		return leftTree.Max();
	}
	else
	{
		while (temp != root)
		{
			if (temp == temp->father->right)
				return temp->father->key;
			temp = temp->father;
		}
	}
	return 0;
}