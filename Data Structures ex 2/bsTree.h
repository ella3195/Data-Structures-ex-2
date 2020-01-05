#ifndef __BSTREE_H
#define __BSTREE_H

#include "bsTreeNode.h"


class BSTree
{
private:
	BSTreeNode *root;

public:
	BSTree() { root = nullptr; }
	BSTree(BSTreeNode* root);
	~BSTree();

	BSTreeNode* getRoot();
	void MakeEmpty();
	void IsEmpty();
	void Delete(BSTreeNode* toDelete);
	void swapMaxLeftTree(BSTreeNode* toDelete);
	BSTreeNode* Find(int id);
	void DeleteRoot();
	void Insert(int id, const char* name);
	void Delete(int id);
	BSTreeNode* findMax();//have max parameter?
	int Min();
	int Max();
	void PrintTree();
};


#endif // !__BSTREE_H
