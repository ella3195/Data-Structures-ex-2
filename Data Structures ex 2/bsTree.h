#ifndef __BSTREE_H
#define __BSTREE_H

#include "bsTreeNode.h" 


class BSTree
{
private:
	BSTreeNode *root;

public:
	BSTree() { root = NULL; }
	~BSTree();

	void MakeEmpty();
	void IsEmpty();
	BSTreeNode* Find(int id);
	void Insert(int id, const char* name);
	void Delete(int id);
	int Min();
	int Max();
	void PrintTree();
};


#endif // !__BSTREE_H
