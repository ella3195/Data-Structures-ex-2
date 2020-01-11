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


//worst = n (one-way tree)
//average = log n (balanced tree)
BSTreeNode* BSTree::Find(int key, int &numComp)
{
	BSTreeNode *temp = root;
	while (temp != nullptr)
	{
		numComp++;//comparing keys
		if (key == temp->getKey())
		{
			return temp;
		}
		else
		{
			numComp++;//comparing keys
			if (key < temp->getKey())
			{
				temp = temp->left;
			}
			else
			{
				temp = temp->right;
			}
		}
	}
}

BSTreeNode* BSTree::Find(int key)
{
	BSTreeNode *temp = root;
	while (temp != nullptr)
	{
		if (key == temp->getKey())
		{
			return temp;
		}
		else
		{
			if (key < temp->getKey())
			{
				temp = temp->left;
			}
			else
			{
				temp = temp->right;
			}
		}
	}
}


//worst = n
//average = log n
void BSTree::Insert(int key, const char* data, int &numComp)
{
	if (Find(key, numComp) != nullptr) 
	{
		return; //  key already exists;
	}
	BSTreeNode* temp = root;
	BSTreeNode* parent = nullptr; //will be parent of newnode
	BSTreeNode* newnode;

	while (temp != nullptr)
	{
		parent = temp;
		numComp++;//comparing keys
		if (key < temp->getKey())
		{
			temp = temp->left;
		}
		else temp = temp->right;
	}

	newnode = new BSTreeNode(key, data, nullptr, nullptr, parent);
	if (parent == nullptr)//empty tree
	{
		root = newnode;
	}
	else
	{
		numComp++;//comparing keys
		if (key < parent->getKey())
		{
			parent->left = newnode;
		}
		else parent->right = newnode;
	}
}

BSTreeNode* BSTree::findMax()//max node in BSTree - most right node
{
	BSTreeNode* max = root;
	while (max->right != nullptr)
		max = max->right;
	return max;
	
}

BSTreeNode* BSTree::findMin()//max node in BSTree - most left node
{
	BSTreeNode* min = root;
	while (min->left != nullptr)
		min = min->left;
	return min;

}

void BSTree::Delete(BSTreeNode* toDelete)
{
	BSTreeNode* father = toDelete->father;
	if (!(toDelete->left)) //no left son
	{
		if (toDelete == father->left) //deleting a left son of father
			father->left = toDelete->right;
		else //deleting a right son of father
			father->right = toDelete->right;
		if (toDelete->right) //updating toDelete's son's father
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
	else //toDelete has 2 sons, need to swap with max node of left sub-tree
	{
		swapMaxLeftTree(toDelete);
	}
}

void BSTree::swapMaxLeftTree(BSTreeNode* toDelete)
{
	BSTree leftTree(toDelete->left);
	BSTreeNode* maxLeft = leftTree.findMax();
	toDelete->data = maxLeft->data;
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
	else //2 sons - swap with max node of left sub-tree
	{
		swapMaxLeftTree(root);
	}
}

void BSTree::Delete(int id, int &numComp)
{
	BSTreeNode* temp = root;
	numComp++;//comparing keys
	if (temp->getKey() == id)//found - root
	{
		DeleteRoot();
		return;
	}
	while (temp != nullptr)
	{
		numComp++;//comparing keys
		if (temp->getKey() < id)
			temp = temp->right;
		else
			temp = temp->left;
		numComp++;//comparing keys
		if (temp->getKey() == id)//found
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
	return min->getKey();
}

int BSTree::Max()
{
	BSTreeNode* max = root;
	while (max->right != nullptr)
		max = max->right;
	return max->getKey();
}

void BSTree::PrintTree()
{
	if (root != nullptr)
	{
		root->InOrder();
	}
	cout << endl;
}

Person* BSTree::FindKthPerson(int &k, int &numComp)
{
	BSTreeNode* KthNode = FindKthNode(root, k);
	return KthNode->data;
}

/*
traverse the tree inorder and counting down from k.
Complexity:
worst = n (if one-way-left tree or if k==n)
average = logn + k = n (k is {0,..,n} so averagely k==n/2)
*/
BSTreeNode* BSTree::FindKthNode(BSTreeNode* root, int &k) //check if works
{
	if (root == nullptr)
		return nullptr;
	FindKthNode(root->left, k);
	if (k == 0)
		return root;
	k--;
	FindKthNode(root->right, k);
	return nullptr;
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
				return temp->father->getKey();
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
				return temp->father->getKey();
			temp = temp->father;
		}
	}
	return 0;
}